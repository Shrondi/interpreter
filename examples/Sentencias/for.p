<< Ejemplo de sentencia for >>

for tabla from 1 to 5 do
        for numero from 1 to 10 do
            print(tabla); print('*'); print(numero); print(' = '); print(tabla*numero); print('\n');
        end_for;

        print('\n');
end_for;

print_string('*** Invertido *** \n\n');

for tabla from 5 to 1 step -1 do
    for numero from 1 to 10 do
        print(tabla); print('*'); print(numero); print(' = '); print(tabla*numero); print('\n');
    end_for;

    print('\n');
end_for;
            