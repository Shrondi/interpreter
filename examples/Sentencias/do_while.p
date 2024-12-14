<< Ejemplo do-while >>

sum := 0;
do
    print('Introduce un numero: ');
    read(numero);

    sum +:= numero;
    
    if (sum >= 10) then
        print('\t*Para salir escribe 0');
        print('\n');
    end_if;


while(numero <> 0.0);