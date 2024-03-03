let bringBack = [];
let interval;

function isNotInBringBack(el){
return !bringBack.some(item => el === item);
}

export default function darkHandler(e){

    if ((localStorage.getItem("darkMode") == "false" || localStorage.getItem("darkMode") == null) || (e == undefined && localStorage.getItem("darkMode") == "true")){

         //add cookie and apply css
        document.querySelector(".highlight").classList.add("highlightMoon");
        localStorage.setItem("darkMode", "true");

        //start a loop that will constantly check for div to make dark a change their color uploading each element to an array so later color can be restored
        interval = setInterval(() => {
            document.querySelectorAll("#app div, #app h1, #app h6, input, button, .chat").forEach(el=>{
                if (window.getComputedStyle(el).backgroundColor == "rgb(255, 255, 255)" && darkMode){
                        bringBack.push(el);
                    el.style.backgroundColor = (el.tagName == "INPUT" || el.tagName == "H6") ? "var(--bs-gray)" : "var(--bs-dark)";
                    el.style.color = "white"
                    if (localStorage.getItem("style") == "old")
                        el.style.border = "2px solid white"
                }
                if (isNotInBringBack(el) && window.getComputedStyle(el).backgroundColor == "rgb(33, 37, 41)")
                {
                    el.style.backgroundColor = "black";
                    el.style.color = "white"
                    if (localStorage.getItem("style") == "old")
                        el.style.border = "2px solid black"
                }
            })
        }, 400);

    }else{

        //removing cookie and apply css
        document.querySelector(".highlight").classList.remove("highlightMoon");
        localStorage.setItem("darkMode", "false");

        clearInterval(interval);

        //looping trough memory array and restore original color
        bringBack.forEach(el=>{
            el.style.backgroundColor = "rgb(255, 255, 255)";
            el.style.color = "black";
        })
        bringBack = [];
    }

    //if this function is called on click avoid the outer div to collapse
    if (e != undefined)
        e.stopPropagation();
}