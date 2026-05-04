//FUNÇÕES GENERALISTAS

//CALCULOS
function inss(salario){
    let contribuicao = 0;
    if(salario<=1621){
        contribuicao = salario*0.075;
    } else if(salario <=2902.84) {
        contribuicao = salario*0.09-24.32;
    } else if(salario <=4354.27) {
        contribuicao = salario*0.12-111.41;
    } else if(salario <=8475.55 ){
        contribuicao = salario*0.14-198.50;
    } else {
        contribuicao = 988.07;
    }

    return contribuicao;
}

function IR(salario){
    let contribuicao = 0;
    if(salario<=5000){
        contribuicao = 0;
    } else if(salario<=6500){
        contribuicao = salario*0.075 - 182.16
    } else if(salario<=8000){
        contribuicao = salario*0.15 - 394.16
    } else if(salario<=10000){
        contribuicao = salario*0.225 - 675.49
    } else {
        contribuicao = salario*0.275 - 908.73
    };
    return contribuicao;
}

function FGTS(salario){
    let contribuicao = salario*0.08;
    return contribuicao;
}

function liquido(salario){
    let liquido = salario-IR(salario)-inss(salario)-FGTS(salario);
    return liquido;
}

//EXIBIÇÃO DE VALORES
function exibirINSS(){
let salario = document.forms[0].bruto;
let bruto = salario.valueAsNumber;
let contribuicao = inss(bruto);
let formatter = new Intl.NumberFormat("pt-BR",{style:"currency",currency: "BRL"});
let output = document.querySelector("#INSS");
output.textContent = formatter.format(contribuicao);
}

function exibirFGTS(){
let salario = document.forms[0].bruto;
let bruto = salario.valueAsNumber;
let contribuicao = FGTS(bruto);
let formatter = new Intl.NumberFormat("pt-BR",{style:"currency",currency: "BRL"});
let output = document.querySelector("#fgts");
output.textContent = formatter.format(contribuicao);
}

function exibirLiquido(){
let salario = document.forms[0].bruto;
let bruto = salario.valueAsNumber;
let contribuicao = liquido(bruto);
let formatter = new Intl.NumberFormat("pt-BR",{style:"currency",currency: "BRL"});
let output = document.querySelector("#liquido");
output.textContent = formatter.format(contribuicao);
}

function exibirIR(){
let salario = document.forms[0].bruto;
let bruto = salario.valueAsNumber;
let contribuicao = IR(bruto);
let formatter = new Intl.NumberFormat("pt-BR",{style:"currency",currency: "BRL"});
let output = document.querySelector("#irrf");
output.textContent = formatter.format(contribuicao);
}

//GESTÃO DE EVENTOS
let button = document.querySelector("input[type='button']");
button.addEventListener("click",exibirINSS);
button.addEventListener("click",exibirFGTS);
button.addEventListener("click",exibirLiquido);
button.addEventListener("click",exibirIR);