<< Calcula los divisores de un numero dado por el usuario >>

print('Escriba un numero: ');
read(num);

cont := 0; #Contador de divisores

for i from 1 to num do

    if ((num%i) = 0) then
        print('Divisor: ');
        print(i);
        print('\n');
      
        cont +:= 1;
    end_if;
end_for;

