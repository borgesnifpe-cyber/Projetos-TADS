//ATIVIDADE 2
const DIARIA = 250, ACRESCIMO = 15;
let totalReserva=0;
let DIAS = prompt("Insira a duração da sua estada:");
if (DIAS>16 && DIAS<=31) {
    totalReserva = DIAS * DIARIA + (ACRESCIMO*(31-DIAS))
    console.log(totalReserva);
} else if (DIAS>31) {
    console.log("Contate a recepção por telefone para consultar valores mensais");
} else {
    totalReserva = DIAS * DIARIA + (ACRESCIMO * 15);
    console.log(totalReserva);
}

//ATIVIDADE 3
