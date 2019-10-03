import "funciones.js";

var numero_simbolos=0, opc=0;
var rango = [], alfabeto1 =[], alfabeto2 = [];

process.stdout.write("Alfabeto_1.");
process.stdout.write("Agregar:\n1. De uno en uno.\n2. Rango.");

process.stdout.write("Elige una opcion:");
process.stdin.on('data', (data) =>{

    opc = data.toString();
    process.exit();
});


switch(parseInt(opc)){

    case 1: 
            process.stdout.write("Cuantos simbolos tendra tu alfabeto:");
            process.stdin.on('data', (data)=>{
                numero_simbolos = data.toString();
                process.exit();
            });

            if(numero_simbolos < 3){
                process.stdout.write("Necesitas al menos 3 símbolos.");
                numero_simbolos = 3;
            }

            Uno_Uno(numero_simbolos, alfabeto1);

            break;

    case 2:

            break;

}
