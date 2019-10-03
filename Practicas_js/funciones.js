
function Uno_Uno(numero_simbolos , alfabeto){

    let simbolo;

    for(let i=0; i<numero_simbolos; i++){
        ProcessingInstruction.stdin.on('data', (data)=> {
            simbolo = data.toString();
        });
        alfabeto.push(simbolo);
    }
}

function Rango(alfabeto, rango){

    let j=0, a = rango[0], b = rango[2];

    
}