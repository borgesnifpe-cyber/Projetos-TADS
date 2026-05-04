console.log(document.documentElement.nodeName);
console.log(document.documentElement.childNodes);
console.log(document.documentElement.nodeType);
console.log(document.body.firstChild.nodeType);

console.log(document.getElementById(123).textContent);
console.log(document.querySelectorAll);
let h1 = document.createElement("h1");
let texto = document.createTextNode("Titulo 1");
let p = document.querySelector("#a123");
document.body.appendChild(h1);
h1.textContent = "Titulo 1";