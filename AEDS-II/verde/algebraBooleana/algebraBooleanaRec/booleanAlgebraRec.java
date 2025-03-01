import java.util.*;

public class booleanAlgebraRec {

    // Substitui as variáveis A, B, C pelos respectivos valores binários
    public static String trocaBinaria(int[] binarios, String booleana) {
        StringBuilder troca = new StringBuilder();
        for (int i = 0; i < booleana.length(); i++) {
            char c = booleana.charAt(i);
            if (c != ' ') {
                if (c == 'A') {
                    troca.append(binarios[0]);
                } else if (c == 'B') {
                    troca.append(binarios[1]);
                } else if (c == 'C') {
                    troca.append(binarios[2]);
                } else {
                    troca.append(c);
                }
            }
        }
        return troca.toString();
    }

    // Função recursiva para avaliar a expressão booleana
    // Utilizamos um array de um elemento para simular passagem por referência do índice
    public static char evaluate(String s, int[] index) {
        // Pula espaços (caso existam)
        while (index[0] < s.length() && s.charAt(index[0]) == ' ') {
            index[0]++;
        }
        // Se o caractere atual for um dígito, retorna-o
        char current = s.charAt(index[0]);
        if (current == '0' || current == '1') {
            index[0]++;
            return current;
        }

        // Caso contrário, espera-se um operador (not, and ou or)
        // Lê o nome do operador até encontrar um caractere não alfabético
        int start = index[0];
        while (index[0] < s.length() && Character.isLetter(s.charAt(index[0]))) {
            index[0]++;
        }
        String op = s.substring(start, index[0]);

        // Avança até encontrar o parêntese de abertura '(' e pula-o
        while (index[0] < s.length() && s.charAt(index[0]) != '(') {
            index[0]++;
        }
        index[0]++; // pula '('

        if (op.equals("not")) {
            // Avalia o único argumento da operação not
            char arg = evaluate(s, index);
            // Pula até o parêntese de fechamento ')'
            while (index[0] < s.length() && s.charAt(index[0]) != ')') {
                index[0]++;
            }
            index[0]++; // pula ')'
            return arg == '1' ? '0' : '1';
        } else if (op.equals("and")) {
            // Lê os argumentos separados por vírgula
            List<Character> args = new ArrayList<>();
            args.add(evaluate(s, index));
            while (index[0] < s.length() && s.charAt(index[0]) == ',') {
                index[0]++; // pula a vírgula
                args.add(evaluate(s, index));
            }
            // Pula o parêntese de fechamento
            if (index[0] < s.length() && s.charAt(index[0]) == ')') {
                index[0]++;
            }
            // Operação AND: se algum argumento for '0', o resultado é '0'
            for (char val : args) {
                if (val == '0') {
                    return '0';
                }
            }
            return '1';
        } else if (op.equals("or")) {
            // Lê os argumentos separados por vírgula
            List<Character> args = new ArrayList<>();
            args.add(evaluate(s, index));
            while (index[0] < s.length() && s.charAt(index[0]) == ',') {
                index[0]++;
                args.add(evaluate(s, index));
            }
            // Pula o parêntese de fechamento
            if (index[0] < s.length() && s.charAt(index[0]) == ')') {
                index[0]++;
            }
            // Operação OR: se algum argumento for '1', o resultado é '1'
            for (char val : args) {
                if (val == '1') {
                    return '1';
                }
            }
            return '0';
        }
        // Caso não corresponda a nenhum operador esperado, retorna '0' por segurança
        return '0';
    }

    // Função que inicia a avaliação recursiva a partir do índice zero
    public static String evaluateExpression(String expr) {
        int[] index = {0};
        char result = evaluate(expr, index);
        return Character.toString(result);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int qtdValores = scanner.nextInt();
        while (qtdValores != 0) {
            int[] binarios = new int[3];
            for (int i = 0; i < qtdValores; i++) {
                binarios[i] = scanner.nextInt();
            }
            scanner.nextLine(); // consome a quebra de linha
            String booleana = scanner.nextLine();
            
            // Substitui as variáveis pelos valores binários
            booleana = trocaBinaria(binarios, booleana);
            // Avalia a expressão booleana de forma recursiva
            String result = evaluateExpression(booleana);
            
            System.out.println(result);
            
            qtdValores = scanner.nextInt();
        }
        scanner.close();
    }
}
