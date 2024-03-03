from itertools import combinations
import time
import logging
import math

logger = logging.getLogger(__name__)


def newton_dynamics(obj, delta_time):
    delta_time_sec = delta_time / 1000 # convert to seconds
    obj.dynamics_constraints()
    obj.vel_x = obj.vel_x + 0.5 * obj.acc_x * delta_time_sec
    obj.pos_x = obj.pos_x + obj.vel_x * delta_time_sec #+ 0.5 * obj.acc_x * (delta_time_sec ** 2)
    #logger.warning(f"LOG ENGINE: pos_x = {obj.pos_x}")
    #logger.warning(f"LOG ENGINE: vel_x = {obj.vel_x}")
    #logger.warning(f"LOG ENGINE: acc_x = {obj.acc_x}")
    obj.vel_y = obj.vel_y + 0.5 * obj.acc_y * delta_time_sec
    obj.pos_y = obj.pos_y + obj.vel_y * delta_time_sec #+ 0.5 * obj.acc_y * (delta_time_sec ** 2)


class Collider:
    def __init__(self, box_width, box_height):
        self.box_width = box_width
        self.box_height = box_height


class CircleCollider(Collider):
    def __init__(self, radius=1):
        self.radius = radius
        super().__init__(box_width=radius, box_height=radius)


class PillCollider(Collider):
    def __init__(self, width=1, height=2):
        self.width = width
        self.height = height
        radius = width / 2
        self.radius = radius
        box_width = width / 2
        box_height = height / 2 + radius
        super().__init__(box_width=box_width, box_height=box_height)


class MyObject:
    def __init__(self, object_id, collider=CircleCollider(), pos_x=0, pos_y=0, vel_x=0, vel_y=0, acc_x=0, acc_y=0):
        self.object_id = object_id
        self.collider = collider
        self.pos_x = pos_x
        self.pos_y = pos_y
        self.vel_x = vel_x
        self.vel_y = vel_y
        self.acc_x = acc_x
        self.acc_y = acc_y
        self.colliding = False

    def on_hit(self, hitted):
        pass

    def hit_left_wall(self, wall_pos, **kwargs):
        pass

    def hit_right_wall(self, wall_pos, **kwargs):
        pass

    def hit_bottom_wall(self, wall_pos, **kwargs):
        pass

    def hit_top_wall(self, wall_pos, **kwargs):
        pass

    def dynamics_constraints(self):
        pass


class Field:
    UPDATE_RATE = 1
    DELTA_LOW_LIMIT = 1_000 / 1 
    DELTA_HIGH_LIMIT = 1_000 / 120
    def __init__(self, objs: list, dinamics, width: int, height: int):
        self.objs = objs
        self.dinamics = dinamics
        self.width = width
        self.height = height
        self.current_time = time.time_ns() // 1_000_000 # convert to milliseconds
        self.last_time = time.time_ns() // 1_000_000 # convert to milliseconds
        self.delta_time = -1
        self.colliding = []

    def add_objects(self, objs: list):
        self.objs.extend(objs)

    def remove_objects(self, objs: list):
        for obj in objs:
            self.objs.remove(obj)

    def update(self):
        self.current_time = time.time_ns() // 1_000_000 # convert to millisencods
        self.delta_time = self.current_time - self.last_time
        # if self.delta_time < 25:
        # logger.warning(f"DELTA_TIME_PRE: {self.delta_time}")
        if self.delta_time > self.DELTA_LOW_LIMIT:
            self.delta_time = self.DELTA_LOW_LIMIT
        elif self.delta_time < self.DELTA_HIGH_LIMIT:
            self.delta_time = self.DELTA_HIGH_LIMIT
        self.update_position()
        self.resolve_collisions()
        self.resolve_interactions()
        self.last_time = time.time_ns() // 1_000_000 # convert to milliseconds

    def update_position(self):
        for obj in self.objs:
            self.dinamics(obj, self.delta_time)
            self.constraints(obj)

    def constraints(self, obj):
        left_pos = obj.pos_x - obj.collider.box_width
        right_pos = obj.pos_x + obj.collider.box_width
        top_pos = obj.pos_y - obj.collider.box_height
        bottom_pos = obj.pos_y + obj.collider.box_height

        if left_pos < 0:
            obj.hit_left_wall(0, width=self.width, height=self.height)
        elif right_pos > self.width:
            obj.hit_right_wall(self.width, width=self.width, height=self.height)
        if top_pos < 0:
            obj.hit_top_wall(0, width=self.width, height=self.height)
        elif bottom_pos > self.height:
            obj.hit_bottom_wall(self.height, width=self.width, height=self.height)

    def resolve_collisions(self):
        for pair in combinations(self.objs, 2):
            if self.collides(pair):
                if pair not in self.colliding:
                    self.colliding.append(pair)
                    pair[0].on_hit(pair[1])
                    pair[1].on_hit(pair[0])
                    pair[0].colliding = True
                    pair[1].colliding = True
            elif pair in self.colliding:
                self.colliding.remove(pair)
                pair[0].colliding = False
                pair[1].colliding = False

    def resolve_interactions(self):
        pass

    def collides(self, pair):
        object_1 = pair[0]
        object_2 = pair[1]
        if isinstance(object_1.collider, CircleCollider) and isinstance(object_2.collider, CircleCollider):
            dist = (object_1.pos_x - object_2.pos_x) ** 2 + (object_1.pos_y - object_2.pos_y) ** 2
            min_dist = object_1.collider.radius ** 2 + object_2.collider.radius ** 2
            if dist < min_dist:
                return True
            else:
                return False
        elif isinstance(object_1.collider, PillCollider) and isinstance(object_2.collider, PillCollider):
            dist_x = abs(object_1.pos_x - object_2.pos_x)
            min_dist_x = (object_1.collider.width + object_2.collider.width) / 2
            dist_y = abs(object_1.pos_y - object_2.pos_y)
            min_dist_y = (object_1.collider.height + object_2.collider.height) / 2
            min_dist_y_with_radius = min_dist_y + (object_1.collider.radius + object_2.collider.radius)
            if dist_x < min_dist_x and dist_y < min_dist_y:
                return True
            elif dist_x < min_dist_x and dist_y < min_dist_y_with_radius:
                high_emisphere_y_1 = object_1.pos_y + object_1.height / 2
                low_emisphere_y_1 = object_1.pos_y - object_1.height / 2
                high_emisphere_y_2 = object_2.pos_y + object_2.height / 2
                low_emisphere_y_2 = object_2.pos_y - object_2.height / 2
                dist_emispheres_1_2 = (object_1.pos_x - object_2.pos_x) ** 2 + (high_emisphere_y_1 - low_emisphere_y_2) ** 2
                dist_emispheres_2_1 = (object_1.pos_x - object_2.pos_x) ** 2 + (low_emisphere_y_1 - high_emisphere_y_2) ** 2
                dist_emispheres = min(dist_emispheres_1_2, dist_emispheres_2_1)
                min_dist_emispheres = object_1.collider.radius ** 2 + object_2.collider.radius ** 2
                if dist_emispheres < min_dist_emispheres:
                    return True
            else:
                return False
        elif isinstance(object_1.collider, CircleCollider) and isinstance(object_2.collider, PillCollider):
            dist_x = abs(object_1.pos_x - object_2.pos_x)
            min_dist_x = object_1.collider.radius + object_2.collider.width / 2
            if dist_x >= min_dist_x:
                return False
            dist_y = abs(object_1.pos_y - object_2.pos_y)
            min_dist_y = object_1.collider.radius + object_2.collider.height / 2
            min_dist_y_with_radius = min_dist_y + object_2.collider.radius
            if dist_y < min_dist_y:
                return True
            elif dist_y < min_dist_y_with_radius:
                high_emisphere_y_2 = object_2.pos_y + object_2.collider.height / 2
                low_emisphere_y_2 = object_2.pos_y - object_2.collider.height / 2
                dist_emispheres_low = (object_1.pos_x - object_2.pos_x) ** 2 + (object_1.pos_y - low_emisphere_y_2) ** 2
                dist_emispheres_high = (object_1.pos_x - object_2.pos_x) ** 2 + (object_1.pos_y - high_emisphere_y_2) ** 2
                dist_emispheres = min(dist_emispheres_low, dist_emispheres_high)
                min_dist_emispheres = object_1.collider.radius ** 2 + object_2.collider.radius ** 2
                if dist_emispheres < min_dist_emispheres:
                    return True
            else:
                return False
        else:
            dist_x = abs(object_1.pos_x - object_2.pos_x)
            min_dist_x = object_2.collider.radius + object_1.collider.width / 2
            if dist_x >= min_dist_x:
                return False
            dist_y = abs(object_1.pos_y - object_2.pos_y)
            min_dist_y = object_2.collider.radius + object_1.collider.height / 2
            min_dist_y_with_radius = min_dist_y + object_1.collider.radius
            if dist_y < min_dist_y:
                return True
            elif dist_y < min_dist_y_with_radius:
                high_emispheres_y_1 = object_1.pos_y + object_1.height / 2
                low_emispheres_y_1 = object_1.pos_y - object_1.height / 2
                dist_emispheres_low = (object_1.pos_x - object_2.pos_x) ** 2 + (object_2.pos_y - low_emisphere_y_1) ** 2
                dist_emispheres_high = (object_1.pos_x - object_2.pos_x) ** 2 + (object_2.pos_y - high_emisphere_y_1) ** 2
                dist_emispheres = min(dist_emispheres_low, dist_emispheres_high)
                if dist_emispheres < min_dist_emispheres:
                    return True
            else:
                return False


class Paddle(MyObject):
    def __init__(self, object_id, height=2, width=4, pos_x=0, pos_y=0, vel_x=0, vel_y=0, acc_x=0, acc_y=0):
        pill_collider = PillCollider(height=height, width=width)
        super().__init__(object_id=object_id, collider=pill_collider, pos_x=pos_x, pos_y=pos_y, vel_x=vel_x, vel_y=vel_y, acc_x=acc_x, acc_y=acc_y)

    def on_hit(self, hitted):
        pass

    def hit_bottom_wall(self, wall_pos, **kwargs):
        self.pos_y = wall_pos - self.collider.box_height
        self.vel_y = 0

    def hit_top_wall(self, wall_pos, **kwargs):
        self.pos_y = wall_pos + self.collider.box_height
        self.vel_y = 0


class Ball(MyObject):
    def __init__(self, object_id, radius=1, pos_x=0, pos_y=0, vel_x=0, vel_y=0, acc_x=0, acc_y=0, max_mod_vel=700):
        circle_collider = CircleCollider(radius=radius)
        self.scores = [0, 0]
        self.last_score = "left"
        self.first_start = False
        self.max_mod_vel = max_mod_vel
        super().__init__(object_id=object_id, collider=circle_collider, pos_x=pos_x, pos_y=pos_y, vel_x=vel_x, vel_y=vel_y, acc_x=acc_x, acc_y=acc_y)

    def on_hit(self, hitted):
        if isinstance(hitted, Paddle):

            # calculate alpha
            hit_zone = self.pos_y - hitted.pos_y
            sign_y = 1 if hit_zone > 0 else -1
            hit_zone = abs(hit_zone)
            mapped = 5 * hit_zone / hitted.collider.box_height
            mapped = 4 if mapped == 5 else mapped
            alpha = int(mapped) * 15
            alpha_rad = alpha * math.pi / 180

            # calculate new velocity
            mod_vel = math.sqrt(self.vel_x ** 2 + self.vel_y ** 2)
            mod_acc = math.sqrt(self.acc_x ** 2 + self.acc_y ** 2)
            sign_x = (-1) * (self.vel_x / abs(self.vel_x))
            self.vel_x = mod_vel * math.cos(alpha_rad) * sign_x
            self.acc_x = mod_acc * math.cos(alpha_rad) * sign_x
            self.vel_y = mod_vel * math.sin(alpha_rad) * sign_y
            self.acc_y = mod_acc * math.sin(alpha_rad) * sign_y
            

    def hit_left_wall(self, wall_pos, **kwargs):
        self.scores[1] += 1
        self.last_score = "right"
        width = kwargs["width"]
        height = kwargs["height"]
        self.pos_x = width / 2
        self.pos_y = height / 2
        self.vel_x = 0
        self.vel_y = 0
        self.acc_x = 0
        self.acc_y = 0

    def hit_right_wall(self, wall_pos, **kwargs):
        self.scores[0] += 1
        self.last_score = "left"
        width = kwargs["width"]
        height = kwargs["height"]
        self.pos_x = width / 2
        self.pos_y = height / 2
        self.vel_x = 0
        self.vel_y = 0
        self.acc_x = 0
        self.acc_y = 0

    def hit_bottom_wall(self, wall_pos, **kwargs):
        self.pos_y = wall_pos - self.collider.box_height
        self.vel_y = - self.vel_y
        self.acc_y = - self.acc_y

    def hit_top_wall(self, wall_pos, **kwargs):
        self.pos_y = wall_pos + self.collider.box_height
        self.vel_y = - self.vel_y
        self.acc_y = - self.acc_y

    def dynamics_constraints(self):
        mod_vel = self.vel_x ** 2 + self.vel_y ** 2
        if mod_vel > self.max_mod_vel ** 2:
            self.acc_x = 0
            self.acc_y = 0


def main_game():
    ball = Ball(object_id="ball", radius=10, pos_x=50, pos_y=50, vel_y=100)
    paddle = Paddle(object_id="paddle", width=10, height=50, pos_y=50, pos_x=405)
    game = Field(objs=[ball], dinamics=newton_dynamics, width=500, height=500)
    while True:
        game.update()
        print(f"pos_x: {ball.pos_x}, pos_y: {ball.pos_y}")
        time.sleep(0.05)
