import Ball from "/viewScripts/pong2d/game/Ball.js";
import Paddle from "/viewScripts/pong2d/game/Paddle.js";
import User from "/viewScripts/pong2d/game/User.js";
import * as API from "/API/APICall.js";
import * as URL from "/API/URL.js";
import * as NOTIFICATION from "/viewScripts/notification/notification.js";
import Router from "/router/mainRouterFunc.js";

const ORIGINAL_WIDTH = 800;
const ORIGINAL_HEIGHT = 450;

let upFlag = true;
let downFlag = true;

let upMsg = true;
let downMsg = true;

function handleProgressBarColor(bar, time, maxTime) {
	let percentage = window.remapValue(time, 0, maxTime, 0, 100);
	if (percentage > 60) {
		bar.style.width = String(percentage) + "%";
	} else if (percentage > 30) {
		bar.style.width = String(percentage) + "%";
		bar.classList.add("bg-warning");
		bar.classList.remove("bg-success");
	} else if (percentage > 0) {
		bar.style.width = String(percentage) + "%";
		bar.classList.remove("bg-warning");
		bar.classList.add("bg-danger");
	}
}

function handleTouchCommands(game) {
	//handle the UP and DOWN control when pressing the relative button (MOBILE)
	document.querySelector(".up").addEventListener("touchstart", (e) => {
		if (upFlag) {
			upFlag = false;
			game[game.currentUser].upInterval = setInterval(() => {
				if (upMsg) {
					game.socket.send(JSON.stringify({ type: `up` }));
					upMsg = false;
				}
				game[game.currentUser].calculatePosition(false);
			}, 10);
		}
	});

	document.querySelector(".start").addEventListener("touchstart", (e) => {
		game.socket.send(JSON.stringify({ type: `start` }));
	});

	document.querySelector(".down").addEventListener("touchstart", (e) => {
		if (downFlag) {
			downFlag = false;
			game[game.currentUser].downInterval = setInterval(() => {
				if (downMsg) {
					game.socket.send(JSON.stringify({ type: `down` }));
					downMsg = false;
				}
				game[game.currentUser].calculatePosition(true);
			}, 10);
		}
	});

	//handle the UP and DOWN control when releasing the relative button (MOBILE)
	document.querySelector(".up").addEventListener("touchend", (e) => {
		upFlag = true;
		game.socket.send(JSON.stringify({ type: `stop` }));
		upMsg = true;
		downMsg = true;
		clearInterval(game[game.currentUser].upInterval);
	});

	document.querySelector(".down").addEventListener("touchend", (e) => {
		downFlag = true;
		game.socket.send(JSON.stringify({ type: `stop` }));
		downMsg = true;
		upMsg = true;
		clearInterval(game[game.currentUser].downInterval);
	});
}

function handleKeyDown(game, e) {
	if ((e.key == "w" || e.key == "ArrowUp") && upFlag) {
		e.preventDefault();
		upFlag = false;
		game[game.currentUser].upInterval = setInterval(() => {
			if (upMsg) {
				try {
					game.socket.send(JSON.stringify({ type: `up` }));
				} catch (e) {
					console.log(e);
				}
				upMsg = false;
			}
			game[game.currentUser].calculatePosition(false);
		}, 10);
	}
	if ((e.key == "s" || e.key == "ArrowDown") && downFlag) {
		e.preventDefault();
		downFlag = false;
		game[game.currentUser].downInterval = setInterval(() => {
			if (downMsg) {
				try {
					game.socket.send(JSON.stringify({ type: `down` }));
				} catch (e) {
					console.log(e);
				}
				downMsg = false;
			}
			game[game.currentUser].calculatePosition(true);
		}, 10);
	}
	if (e.key == "p") {
		game.socket.send(JSON.stringify({ type: "start" }));
		document.querySelector(".gameStart").style.display = "none";
	}
	if (e.key == " ") document.querySelector("#myCanv").requestFullscreen();
}

function handleKeyUp(game, e) {
	if (e.key == "w" || e.key == "ArrowUp") {
		upFlag = true;
		game.socket.send(JSON.stringify({ type: `stop` }));
		upMsg = true;
		downMsg = true;
		clearInterval(game[game.currentUser].upInterval);
	}
	if (e.key == "s" || e.key == "ArrowDown") {
		downFlag = true;
		game.socket.send(JSON.stringify({ type: `stop` }));
		downMsg = true;
		upMsg = true;
		clearInterval(game[game.currentUser].downInterval);
	}
}

function checkMessage(game, msg) {
	if (msg.message == "game starts") {
		if (window.innerWidth > 900) {
			document.addEventListener("keyup", game.upHandler);
			document.addEventListener("keydown", game.downHandler);
		} else {
			handleTouchCommands(game);
		}
		document.querySelector(".gameOverlay").style.transform =
			"translateX(100%)";
		game.currentUser =
			msg.player_pos == "right" ? "paddleRight" : "paddleLeft";
		game.activeUser.initPlayer(msg.player_pos);
		game.opponent.initPlayer(msg.player_pos == "left" ? "right" : "left");
	} else if (msg.message == "Game is finished") {
		document.removeEventListener("keyup", game.upHandler);
		document.removeEventListener("keydown", game.downHandler);
		localStorage.setItem("stop", "true");
		game.gameOst.pause();
		if (game.activeUser.sound != 0) game.activeUser.sound.pause();
		if (
			Number(game.activeUser.scoreDisplay.innerHTML.trim()) >
			Number(game.opponent.scoreDisplay.innerHTML.trim())
		) {
			document.querySelector(".gameOverlayWin").style.transform =
				"translate(0)";
			window.playFile("/sound/finalGameWin.mp3");
		} else if (
			Number(game.activeUser.scoreDisplay.innerHTML.trim()) ==
			Number(game.opponent.scoreDisplay.innerHTML.trim())
		) {
			document.querySelector(".gameOverlayDraw").style.transform =
				"translate(0)";
			window.playFile("/sound/finalGameWin.mp3");
		} else {
			document.querySelector(".gameOverlayLoose").style.transform =
				"translate(0)";
			window.playFile("/sound/finalGameOver.mp3");
		}
	} else if (msg.message == "Apparently you connected to late") {
		NOTIFICATION.simple({
			title: "Game:",
			body: "You have Connected Too late the game it's lost...",
		});
		Router();
	} else if (msg.message == "The other player has been disconnected") {
		game.gameOst.pause();
		localStorage.setItem("stop", "true");
		document.querySelector(".gameOverlayWin").style.transform =
			"translate(0)";
		window.playFile("/sound/finalGameWin.mp3");
	} else if (msg.message == "The other player doesn't show up") {
		game.gameOst.pause();
		localStorage.setItem("stop", "true");
		document.querySelector(".gameOverlayWin").style.transform =
			"translate(0)";
		window.playFile("/sound/finalGameWin.mp3");
	}
}

function handleSocketMesssage(game, message) {
	let msg = JSON.parse(message.data);

	if (msg.message != undefined) checkMessage(game, msg);

	if (msg.objects != undefined) {
		if (game.ball.deltaX != 0)
			document.querySelector(".gameWait").style.display = "none";
		game.activeUser.updateScore(msg.objects.score);
		game.opponent.updateScore(msg.objects.score);
	}

	if (msg.objects != undefined) {
		if (game.maxTime == undefined) game.maxTime = msg.objects.time;
		handleProgressBarColor(
			document.querySelector(".progress-bar"),
			msg.objects.time,
			game.maxTime
		);
		msg.objects.ball.acc_x =
			(msg.objects.ball.acc_x * game.canvas.width) / ORIGINAL_WIDTH;
		msg.objects.ball.acc_y =
			(msg.objects.ball.acc_y * game.canvas.height) / ORIGINAL_HEIGHT;

		msg.objects.ball.vel_x =
			(msg.objects.ball.vel_x * game.canvas.width) / ORIGINAL_WIDTH +
			msg.objects.ball.acc_x;
		msg.objects.ball.vel_y =
			(msg.objects.ball.vel_y * game.canvas.height) / ORIGINAL_HEIGHT +
			msg.objects.ball.acc_y;

		msg.objects.ball.x =
			(msg.objects.ball.x * game.canvas.width) / ORIGINAL_WIDTH;
		msg.objects.ball.y =
			(msg.objects.ball.y * game.canvas.height) / ORIGINAL_HEIGHT;
		if (msg.objects != undefined) {
			if (
				Math.sign(msg.objects.ball.vel_x) !=
					Math.sign(game.ball.deltaX) ||
				Math.sign(msg.objects.ball.vel_y) != Math.sign(game.ball.deltaY)
			) {
				game.ball.updatePosition(
					msg.objects.ball.x,
					msg.objects.ball.y,
					msg.objects.ball.vel_x,
					msg.objects.ball.vel_y
				);
				game.positionUpdated = true;
				window.playFile("/sound/ballHit.wav");
			}
			if (
				Math.abs(msg.objects.ball.x - game.ball.x) > 2 ||
				Math.abs(msg.objects.ball.y - game.ball.y) > 2
			) {
				game.ball.updatePosition(
					msg.objects.ball.x,
					msg.objects.ball.y,
					msg.objects.ball.vel_x,
					msg.objects.ball.vel_y
				);
				game.positionUpdated = true;
			}
			game.paddleLeft.updatePosition(
				msg.objects.paddle_left.x,
				msg.objects.paddle_left.y
			);
			game.paddleRight.updatePosition(
				msg.objects.paddle_right.x,
				msg.objects.paddle_right.y
			);
		}
	}
}

export default class {
	constructor(gameCfg) {
		this.maxTime = undefined;
		this.gameTicket = gameCfg.gameTicket;
		this.previusTime = gameCfg.previousTime;
		this.width = gameCfg.width;
		this.height = gameCfg.height;
		this.canvas = gameCfg.canvas;
		this.currentUser = gameCfg.currentUser;
		this.canvas.width = gameCfg.width;
		this.canvas.height = gameCfg.height;
		this.texture = gameCfg.texture == undefined ? "" : gameCfg.texture;
		this.paddleLeft = new Paddle(this.canvas, gameCfg.padleLeftConfig);
		this.paddleRight = new Paddle(this.canvas, gameCfg.padleRightConfig);
		this.ball = new Ball(this.canvas, gameCfg.ballConfig);
		this.ctx = gameCfg.canvas.getContext("2d");
		this.image = new Image();
		this.image.src = this.texture;
		this.positionUpdated = false;
		this.socket;
		this.upHandler = handleKeyUp.bind(null, this);
		this.downHandler = handleKeyDown.bind(null, this);
		this.activeUser = new User(
			localStorage.getItem("username"),
			gameCfg.userDisplayName
		);
		this.opponent = new User(
			gameCfg.opponentName,
			gameCfg.opponentDisplayName
		);
		this.gameOst = window.playFileLoop("/sound/gameOst.mp3");

		API.startQueque(1)
			.then((res) => {
				if (gameCfg.opponentDisplayName == undefined)
					this.socket = new WebSocket(
						`${URL.socket.GAME_SOCKET}?ticket=${res.ticket}&token=${
							this.gameTicket
						}&username=${localStorage.getItem("username")}`
					);
				else
					this.socket = new WebSocket(
						`${URL.socket.TOURNAMENT_SOCKET}?ticket=${
							res.ticket
						}&token=${
							this.gameTicket
						}&username=${localStorage.getItem(
							"username"
						)}&tournament_id=${gameCfg.tournamentId}`
					);
				this.socket.onopen = () => {
					this.socket.addEventListener(
						"message",
						handleSocketMesssage.bind(null, this)
					);
				};
			})
			.catch((e) => {
				console.log(e);
			});

		NOTIFICATION.simple({
			title: "Fullscreen:",
			body: "press spacebar to enter fullscreen",
		});
	}

	draw() {
		if (this.texture == "") {
			this.ctx.fillStyle = "#000000";
			this.ctx.fillRect(0, 0, this.canvas.width, this.canvas.height);
		} else {
			this.ctx.drawImage(
				this.image,
				0,
				0,
				this.canvas.width,
				this.canvas.height
			);
		}
		this.ball.draw();
		this.paddleLeft.draw();
		this.paddleRight.draw();
	}

	getRefreshRate(iterations = 3) {
		return new Promise((resolve) => {
			let frameCount = 0;
			let startTime;
			let iterationCount = 0;

			function countFrames(timestamp) {
				if (!startTime) {
					startTime = timestamp;
				}

				frameCount++;

				if (timestamp - startTime > 1000) {
					iterationCount++;

					if (iterationCount === iterations) {
						const refreshRate =
							frameCount / ((timestamp - startTime) / 1000);
						resolve(refreshRate.toFixed(2));
						iterationCount = 0;
					} else {
						frameCount = 0;
						startTime = timestamp;
						requestAnimationFrame(countFrames);
					}
				} else {
					requestAnimationFrame(countFrames);
				}
			}
			requestAnimationFrame(countFrames);
		});
	}
}
