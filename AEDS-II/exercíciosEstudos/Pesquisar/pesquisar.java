


class Contato{

    String cpf;
    String nome;
    String telefone;
    String email;

    public Contato(String cpf, String nome, String telefone, String email){
        this.cpf = cpf;
        this.nome = nome;
        this.telefone = telefone;
        this.email = email;
    }
}

class Agenda{
    
    private Contato[] contatos;
    private int tamanho;

    public Agenda(int capacidade){
        contatos = new Contato[capacidade];
        tamanho = 0;
    }

    public void adicionarContato(Contato contato){
       
        if(tamanho < contatos.length){
            contatos[tamanho++] = contato;
        } else{
            System.out.println("Agenda cheia!");
        }
    }

    public Contato pesquisarPorNome(String nome){
        
        for(int i = 0; i < tamanho; i++){
            if(contatos[i].nome.equalsIgnoreCase(nome)){
                return contatos[i];
            }
        }
        return null; 
    }

    public Contato pesquisarPorCpf(String cpf){
        
        for(int i = 0; i < tamanho; i++){
            if(contatos[i].cpf.equals(cpf)){
                return contatos[i];
            }
        }
        return null; 
    }
}