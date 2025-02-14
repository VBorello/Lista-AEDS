using System;

class Bota
{
    private int tamanho;
    private char lado;

    public Bota() { }

    public Bota(int tamanho, char lado)
    {
        this.tamanho = tamanho;
        this.lado = lado;
    }

    public int GetTamanho()
    {
        return tamanho;
    }

    public char GetLado()
    {
        return lado;
    }

    public void SetTamanho(int tamanho)
    {
        this.tamanho = tamanho;
    }

    public void SetLado(char lado)
    {
        this.lado = lado;
    }

    public bool FormarPar(Bota pe)
    {
        return (this.tamanho == pe.GetTamanho()) &&
               ((this.lado == 'D' && pe.GetLado() == 'E') ||
                (this.lado == 'E' && pe.GetLado() == 'D'));
    }
}

class Program
{
    static void Main()
    {
        int quantidadeBotas = int.Parse(Console.ReadLine());
        
        Bota[] botas = new Bota[10000];
        int pares = 0;
        int total = 0;

        for (int i = 0; i < quantidadeBotas; i++)
        {
            string[] input = Console.ReadLine().Split(' ');
            int tamanho = int.Parse(input[0]);
            char lado = char.Parse(input[1]);

            if (lado != 'D' && lado != 'E')
            {
                Environment.Exit(1);
            }

            Bota pe2 = new Bota(tamanho, lado);
            int ePar = -1;

            for (int j = 0; j < total; j++)
            {
                if (pe2.FormarPar(botas[j]))
                {
                    ePar = j;
                    break;
                }
            }

            if (ePar != -1)
            {
                for (int j = ePar; j < total - 1; j++)
                {
                    botas[j] = botas[j + 1];
                }

                total--;
                pares++;
            }
            else
            {
                botas[total] = new Bota(tamanho, lado);
                total++;
            }
        }

        Console.WriteLine(pares);
    }
}
