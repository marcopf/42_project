import Aview from "/views/abstractView.js";
import pongLoader from "/viewScripts/pong2d/loader.js"
import startGame from "/viewScripts/pong2d/startMatch.js"
import handleSlider from "/viewScripts/pong2d/sliders.js"
import * as API from"/API/APICall.js"
import * as URL from"/API/URL.js"

let pills = ["/imgs/pillsTexture/classicPong.png", "/imgs/pillsTexture/pill1.png", "/imgs/pillsTexture/pill.png"]
let grounds = ["/imgs/groundTexture/pong-thumbnail.jpg", "/imgs/groundTexture/ground1.jpg", "/imgs/groundTexture/ground2.avif", "/imgs/groundTexture/ground3.jpg"]
let balls = ["/imgs/ballTexture/classicBall.png", "/imgs/ballTexture/tennis.png", "/imgs/ballTexture/basket.png", "/imgs/ballTexture/soccer.png"]
let gameObj = 0;
let socket = 0;

function composeUrl(ticket, token){
    if (token != undefined){
        let url = `${URL.matchReq.MATCH_REQ_SOCKET}?ticket=${ticket}&username=${localStorage.getItem("username")}&match_token=${token}`;

        history.pushState(null, null, "/games/pong2d/");
        return (url)
    }
    return (`${URL.socket.QUEUE_SOCKET}?ticket=${ticket}&username=${localStorage.getItem("username")}`);
}

export default class extends Aview{
    constructor(){
        super();
        this.pillTexture = pills[0];
        this.groundTexture = grounds[0];
        this.ballTexture = balls[0];
        this.game = 0;
    }

    getGameHtml(){
        document.querySelector(".chatContainer").style.zIndex = "-1";
        return `
        <div class="base">
            <div class="left">
                <div id="opponentDisplay">
                    <h4 class="user1"></h4>
                    <h2>0</h2>
                </div>
                <div id="currentUserDisplay">
                    <h4 class="user2"></h4>
                    <h2>0</h2>
                </div>
                <div class="progress">
                    <div class="progress-bar progress-bar-striped progress-bar-animated bg-success" role="progressbar" aria-valuenow="75" aria-valuemin="0" aria-valuemax="100" style="width: 100%"></div>
                </div>
                <div id="gameAdvice">
                    <ul>
                        <li>${this.language.pong2d.advices[0]}</li>
                        <li>${this.language.pong2d.advices[1]}</li>
                        <li>${this.language.pong2d.advices[2]}</li>
                        <li>${this.language.pong2d.advices[3]}</li>
                    </ul>
                    <h5 class="gameStart">
                        ${this.language.pong2d.gameStart}
                    </h5>
                    <h5 class="gameWait">
                        ${this.language.pong2d.gameWait}
                    </h5>
                </div>
            </div>
            <div class="center">
                <div class="display">
                    <div id="opponentDisplayMobile">
                        <h4></h4>
                        <h2>0</h2>
                    </div>
                    <div id="currentUserDisplayMobile">
                        <h4></h4>
                        <h2>0</h2>
                    </div>
                </div>
                <div class="gameContainerPadding">
                    <div class="gameContainer">
                        <div class="gameOverlay">
                            <div class="gameLoader spinner-border" role="status">
                            </div>
                        </div>
                        <div class="gameOverlayWin">
                            <h2>${this.language.pong2d.win}</h2>
                            <a href="/games/pong2d/" data-link>${this.language.pong2d.playAgain}</a>
                        </div>
                        <div class="gameOverlayDraw">
                            <h2>${this.language.pong2d.draw}</h2>
                            <a href="/games/pong2d/" data-link>${this.language.pong2d.playAgain}</a>
                        </div>
                        <div class="gameOverlayLoose">
                            <h2>${this.language.pong2d.lost}</h2>
                            <a href="/games/pong2d/" data-link>${this.language.pong2d.playAgain}</a>
                        </div>
                        <canvas id="myCanv"></canvas>
                    </div>
                </div>
                <div clsss="gameInfoBox">
                </div>
                <div class="mobileControl">
                    <div class="mobile up">⬆</div>
                    <div class="mobile start">${this.language.pong2d.start}</div>
                    <div class="mobile down">⬇</div>
                </div>
            </div>
        </div>
        `
    }
    getHtml(){
        return `
        <div class="base">
            <div class="themeContainer">
                <div class="pillsTheme">
                    <div class="themeDisplay">
                        <div class="sliderPill">
                        </div>
                    </div>
                    <div class="info">
                    <h3>${this.language.pong2d.pillStyle}</h3>
                    <div class="nextPill">
                        >
                    </div>
                    </div>
                </div>
                <div class="groundTheme">
                    <div class="themeDisplay">
                        <div class="sliderGround">
                        </div>
                    </div>
                    <div class="info">
                    <h3>${this.language.pong2d.groundStyle}</h3>
                        <div class="nextGround">
                            >
                        </div>
                    </div>
                </div>
                <div class="ballTheme">
                    <div class="themeDisplay">
                        <div class="sliderBall">
                        </div>
                    </div>
                    <div class="info">
                    <h3>${this.language.pong2d.ballStyle}</h3>
                    <div class="nextBall">
                        >
                    </div>
                    </div>
                </div>
            </div>
            <div class="btnContainer">
                <div class="btnWindow">
                    <h1>${this.language.pong2d.pongQueue}</h1>
                    <canvas id="waitCanv" style="display: none;"></canvas>
                    <div id="startQueque">
                        ${this.language.pong2d.enterQueue}
                    </div>
                </div>
            </div>
        </div>
        `
    }

    startQueueBtn(token){
        document.querySelector("#startQueque").innerHTML = `
        <div>
            ${this.language.pong2d.searchingOpp}
        </div>

        <button class="stopSearching">X</button> 
        ` 
        API.startQueque(1).then(res=>{
            if (res == undefined)
                return ;
            socket = new WebSocket(composeUrl(res.ticket, token));
            socket.onopen = ()=>{
                socket.addEventListener("message", (message)=>{
                    let msg = JSON.parse(message.data);
                    localStorage.setItem("gameStarted", "true");
                    document.querySelector("#app").innerHTML = this.getGameHtml();
                    socket.close();
                    socket = 0;
                    gameObj = startGame(this.ballTexture, this.groundTexture, this.pillTexture, msg);
                })
            } 
        }).catch(e=>{
            console.log(e)
        })
    }

    defineQueue(params){
        const url = window.location.href;

        document.querySelector("#startQueque").addEventListener("click", async ()=>{
            document.querySelector(".btnWindow").style.height = "50%";
            document.querySelector("#waitCanv").style.display= "flex";
            document.querySelector("#startQueque").style.justifyContent = "space-between";

            if (document.querySelector("#startQueque").innerHTML.trim() != this.language.pong2d.enterQueue)
                this.restoreQueueBtn()
            else
                this.startQueueBtn(params.get("token") ?? undefined)
        })
    }

    restoreQueueBtn(){
        document.querySelector("#waitCanv").style.display= "none";
        document.querySelector(".btnWindow").style.height = "30%";
        document.querySelector("#startQueque").style.justifyContent = "center";
        document.querySelector("#startQueque").innerHTML = `Enter !`
        socket.close();
    }

	setup(){
        this.defineWallpaper("/imgs/backLogin.png", "/imgs/modernBack.jpeg");
        let params = new URLSearchParams(window.location.search)

        if (params.size > 1){
            document.querySelector("#app").innerHTML = this.getGameHtml();
            let conf = {
                user1: localStorage.getItem("username"),
                userDisplay: params.get("userDisplay"),
                user2: params.get("opponent"),
                opponentDisplay: params.get("opponentDisplay"),
                tournamentId: params.get("tournamentId"),
                ticket: params.get("token")
            }
            gameObj = startGame(this.ballTexture, this.groundTexture, this.pillTexture, conf);
            history.pushState(null, null, "/games/pong2d/");
            return ;
        }

        document.querySelector("#waitCanv").style.width = "100%"
        document.querySelector("#waitCanv").style.height = "50%"
        localStorage.setItem("gameStarted", "false");

        handleSlider(".sliderPill", ".nextPill", pills, "pillTexture", this);
        handleSlider(".sliderGround", ".nextGround", grounds, "groundTexture", this);
        handleSlider(".sliderBall", ".nextBall", balls, "ballTexture", this);

        pongLoader();
        this.defineQueue(params);
    }

    destroy(){
        document.querySelector(".chatContainer").style.zIndex = "10000000000";
        if (socket != 0){
            socket.close();
        }
        if (gameObj != 0){
            gameObj.socket.close(3002);
            gameObj.gameOst.pause();
        }
        document.removeEventListener("keyup", gameObj.upHandler)
        document.removeEventListener("keydown", gameObj.downHandler)
        localStorage.setItem("stop", "true")
    }
	
}