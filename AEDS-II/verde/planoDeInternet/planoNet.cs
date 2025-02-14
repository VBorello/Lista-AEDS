using System;

class Program {
    static void Main() {
    
        int plano = int.Parse(Console.ReadLine());
        int meses = int.Parse(Console.ReadLine());

        int sobra = plano;

        for (int i = 0; i < meses; i++) {
            int gasto = int.Parse(Console.ReadLine());
            sobra += plano - gasto;
        }

        Console.WriteLine(sobra);
    }
}
