function criaTabuada(a,b) {
    let matriz1 = [];
    for (i=a ;i<=b ;i++) {
    tabuadaTemp = [];
        for (c=1;c<=10;c++) {
            result = i*c;
            text = i + "*" + c + "=" + result;
            tabuadaTemp.push(text.toString());
        }
    matriz1.push(tabuadaTemp);
    }
    return matriz1;
};
var a = 3,b=8;
tabuada1 = criaTabuada(a,b);
let elementoPosition = createTextNode(tabuada1);
document.getElementById("num1").appendChild(elementoPosition);