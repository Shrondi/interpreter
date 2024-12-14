print('* Escribe 1 para borrar la pantalla\n');
print('* Escribe 2 para cambiar el cursor\n');
print('* Escribe 3 para cambiar el color a amarillo\n');
read(numero);

case(numero)
    value 1: clear_screen; print('Pantalla borrada!');

    value 2: 
            print_string('Escribe la coordenada x: ');
            read(x);

            print_string('Escribe la coordenada y: ');
            read(y);

            place(x,y);
            print('Cursor cambiado!');

    value 3: 
        style('yellow');
        print('Color cambiado!');


    default:
            print('Numero incorrecto');

end_case;