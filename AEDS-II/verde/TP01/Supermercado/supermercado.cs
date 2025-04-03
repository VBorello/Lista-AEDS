using System;

class Supermercado
{
    static int LerMercados()
    {
        return int.Parse(Console.ReadLine());
    }

    static double CalcularPrecos(int qtdMercados)
    {
        double menorPreco = double.MaxValue;

        for (int i = 0; i < qtdMercados; i++)
        {
            string[] entrada = Console.ReadLine().Split();
            double preco = double.Parse(entrada[0], System.Globalization.CultureInfo.InvariantCulture);
            int gramas = int.Parse(entrada[1]);
            
            double precoPorKg = (preco / gramas) * 1000;
            
            if (precoPorKg < menorPreco)
            {
                menorPreco = precoPorKg;
            }
        }

        return menorPreco;
    }

    static void Main()
    {
        int qtdMercados = LerMercados();
        double menorPreco = CalcularPrecos(qtdMercados);
        
        Console.WriteLine(menorPreco.ToString("F2", System.Globalization.CultureInfo.InvariantCulture));
    }
}
