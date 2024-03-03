let ip = "localhost";
let port = "8000";
let protocol = "https";
let pongPort = "7000";
let chatSocketPort = "9001"
let notificationSocketPort = "9000"
let authPort = "8000"

export const availabilityCheck = {
    USERNAME: `${protocol}://${ip}:${port}/users/check/`,
    EMAIL: `${protocol}://${ip}:${port}/users/check/`,
}

export const general = {
    USER_INFO: `${protocol}://${ip}:${port}/users/info/`,
    GET_USERS: `${protocol}://${ip}:${port}/users/`,
    INTRA_URL: `${protocol}://${ip}:${authPort}/oauth2/intra/url/`,
    CONVERT_INTRA_TOKEN: `${protocol}://${ip}:${authPort}/oauth2/intra/login/`,
    LINK_INTRA_TOKEN_ACCOUNT: `${protocol}://${ip}:${authPort}/oauth2/intra/link/`,
    UNLINK_INTRA_TOKEN_ACCOUNT: `${protocol}://${ip}:${authPort}/oauth2/intra/unlink/`,
}

export const auth = {
    ACTIVATE_TFA: `${protocol}://${ip}:${port}/2fa/manage/`,
    GET_EMAIL_CODE: `${protocol}://${ip}:${port}/2fa/otp/`,
    VALIDATE_CODE: `${protocol}://${ip}:${port}/2fa/validate/activate/`,
    VALIDATE_CODE_LOGIN: `${protocol}://${ip}:${port}/2fa/validate/login/`,
    VALIDATE_CODE_RECOVERY: `${protocol}://${ip}:${port}/2fa/validate/recover/`,
    CHECK_TFA_STATUS: `${protocol}://${ip}:${port}/2fa/manage/`,
    REMOVE_TFA: `${protocol}://${ip}:${port}/2fa/manage/`,
    SEND_RECOVERY_CODE: `${protocol}://${ip}:${port}/auth/recovery/`,
    UPDATE_PASSWORD: `${protocol}://${ip}:${port}/auth/password/`,
    INTRA_STATUS: `${protocol}://${ip}:${authPort}/oauth2/linked/`,

    GET_GOOGLE_URL: `${protocol}://${ip}:${authPort}/oauth2/google/v2/url/`,
    UNLINK_GOOGLE_ACCOUNT: `${protocol}://${ip}:${authPort}/oauth2/google/unlink/`,
    LINK_GOOGLE_ACCOUNT: `${protocol}://${ip}:${authPort}/oauth2/google/v2/link/`,
    LOGIN_WITH_GOOGLE: `${protocol}://${ip}:${authPort}/oauth2/google/v2/login/`,
    VALIDATE_EMAIL: `${protocol}://${ip}:${authPort}/auth/email/`,
}

export const stats = {
    PIE_STATS: `${protocol}://${ip}:${port}/pong/matches/results/all/`,
    RADAR_CHART: `${protocol}://${ip}:${port}/pong/matches/stats/`,
    ISTOGRAM_CHART: `${protocol}://${ip}:${port}/pong/matches/results/`,

}

export const friendship = {
    SEND_REQUEST: `${protocol}://${ip}:${port}/friends/request/send/`,
    REMOVE_FRIEND: `${protocol}://${ip}:${port}/friends/request/delete/`,
    ACCEPT_REQUEST: `${protocol}://${ip}:${port}/friends/request/accept/`,
    DENY_REQUEST: `${protocol}://${ip}:${port}/friends/request/reject/`,
    FRIEND_STATUS: `${protocol}://${ip}:${port}/friends/`,
    GET_FRIENDS: `${protocol}://${ip}:${port}/friends/all/`,
}

export const socket = {
    CHAT_SOCKET: `${protocol == "https" ? "wss" : "ws"}://${ip}:${chatSocketPort}/ws/chat/socket/`,
    NOTIFICATION_SOCKET: `${protocol == "https" ? "wss" : "ws"}://${ip}:${notificationSocketPort}/ws/notification/socket/`,
    GAME_SOCKET: `${protocol == "https" ? "wss" : "ws"}://${ip}:${pongPort}/ws/game/socket/`,
    TOURNAMENT_SOCKET: `${protocol == "https" ? "wss" : "ws"}://${ip}:${pongPort}/ws/tournament/socket/`,
    QUEUE_SOCKET: `${protocol == "https" ? "wss" : "ws"}://${ip}:${pongPort}/ws/matchmaking/queue/`,
    
    NOTIFICATION_SOCKET_TICKET: `${protocol}://${ip}:${port}/auth/ticket/ntf/`,
    CHAT_SOCKET_TICKET: `${protocol}://${ip}:${port}/auth/ticket/chat/`,
    GET_QUEQUE_TICKET: `${protocol}://${ip}:${port}/auth/ticket/matchmaking/`,
    GET_CHAT_HISTORY: `${protocol}://${ip}:${port}/chat/messages/`,
}

export const userAction = {
    REFRESH_TOKEN: `${protocol}://${ip}:${authPort}/auth/refresh/`,
    LOGIN: `${protocol}://${ip}:${authPort}/auth/login/`,
    LOGOUT: `${protocol}://${ip}:${authPort}/auth/logout/`,
    LOGOUT_ALL: `${protocol}://${ip}:${authPort}/auth/logout/all/`,
    REGISTER: `${protocol}://${ip}:${port}/register/`,
    UPDATE_INFO: `${protocol}://${ip}:${port}/users/info/update/`,
    UPDATE_PHOTO: `${protocol}://${ip}:${port}/users/image/upload/`,
    UPDATE_EMAIL: `${protocol}://${ip}:${port}/users/email/update/`,
    UPDATE_PASSWORD: `${protocol}://${ip}:${port}/users/password/update/`,

    TEST: `${protocol}://${ip}:${port}/users`
}

export const tournaments = {
    CREATE: `${protocol}://${ip}:${port}/pong/tournaments/create/`,
    UNREGISTER: `${protocol}://${ip}:${port}/pong/tournaments/unregister/`,
    GET_TOURNAMENTS_LIST: `${protocol}://${ip}:${port}/pong/tournaments/`,
    REGISTER: `${protocol}://${ip}:${port}/pong/tournaments/register/`,
    GET_MATCH_HISTORY: `${protocol}://${ip}:${port}/pong/matches/`,
    GET_TOURNAMENT_HISTORY: `${protocol}://${ip}:${port}/pong/tournaments/schema/`,
}

export const matchReq = {
    SEND_REQUEST:  `${protocol}://${ip}:${port}/pong/match/`,
    DELETE_REQUEST:  `${protocol}://${ip}:${port}/pong/match/delete/`,
    REJECT_REQUEST:  `${protocol}://${ip}:${port}/pong/match/reject/`,
    ACCEPT_REQUEST:  `${protocol}://${ip}:${port}/pong/match/accept/`,

    MATCH_REQ_SOCKET: `${protocol == "https" ? "wss" : "ws"}://${ip}:${pongPort}/ws/match/queue/`
}

export const manageUsers ={
    //come delete
    DELETE_USER: `${protocol}://${ip}:${port}/users/`,
    //path
    MANAGE_BAN: `${protocol}://${ip}:${port}/users/ban/`,
    MANAGE_MODERATOR: `${protocol}://${ip}:${port}/users/role/`
}
