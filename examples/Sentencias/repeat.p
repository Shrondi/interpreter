<< Ejemplo sentencia repeat >>

sum := 0;
number := 10;
repeat
   sum := sum + number;

   print(sum);
   print_string('\n');

   number := number - 2;
until (number = 0);