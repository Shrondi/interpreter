<< Uso de la sentencia if-else >>

if (2) then
    print('El numero es distinto de 0');
else
    print_string('El numero es 0');
end_if;

print_string('\n');
print('Introduce un numero: ');
read(numero);

if (numero > 0) then
    print('El número es positivo.');
else
    if (numero < 0) then 
        print('El número es negativo.');
    else
        print('El número es cero.');
    end_if;
end_if;