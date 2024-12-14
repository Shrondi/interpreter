<< Ejemplo sentencia case >>

flag := true;
do 
    print('\nIntroduce el dia de la semana: ');
    read(dia);

    case (dia)
            value 1: print_string('Lunes'); flag := false;
            value 2: print_string('Martes'); flag := false;
            value 3: print_string('Miercoles'); flag := false;
            value 4: print_string('Jueves'); flag := false;
            value 5: print_string('Viernes'); flag := false;
            value 6: print_string('Sabado'); flag := false;
            value 7: print_string('Domingo'); flag := false;
        default:
            print('Dia no valido');
    end_case;

while(flag);