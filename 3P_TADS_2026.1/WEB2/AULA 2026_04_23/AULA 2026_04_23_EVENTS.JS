function teste() {
    alert('Hello!!');
}
function teste2() {
    alert('Hello2!!!')
}
function teste3(){
    alert('Hello3!!!!!!!!')
}

let p = document.getElementById("abc");
//p.onclick = alert("Hello");
//p.onclick = teste;
p.addEventListener("click",teste);
p.addEventListener ("click",teste2);
p.onclick = teste3;