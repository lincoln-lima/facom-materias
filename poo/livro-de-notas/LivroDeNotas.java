/**
 * Classe usada para gerenciar as notas dos alunos inscritos em uma disciplina.
 */
public class LivroDeNotas
{
  private String nomeDaDisciplina;
  private String nomeDoProfessor;
  private int quantidadeDeVagas;
  private float mediaAprovacao;
  
  private String[] nomesDosAlunos;
  private float[] notasDosAlunos;
  private int matriculados = 0;
  
  /**
   * Método construtor da classe "LivroDeNotas".
   * 
   * O construtor recebe quatro parâmetros: o nome da disciplina, o nome do professor responsável pela disciplina,
   * a quantidade de vagas ofertadas pela disciplina e a média de aprovação que a disciplina deve usar para
   * informar se toda a turma está aprovada ou não.
   * 
   * @param nomeDaDisciplina Nome da disciplina ofertada.
   * @param nomeDoProfessor Nome do professor responsável pela disciplina.
   * @param quantidadeDeVagas Quantidade de vagas ofertadas pela disciplina.
   * @param mediaAprovacao Nota usada para verificar se toda a turma foi aprovada ou reprovada.
   */
  public LivroDeNotas(String nomeDaDisciplina, String nomeDoProfessor, int quantidadeDeVagas, float mediaAprovacao)
  {
    // TODO
    this.nomeDaDisciplina = nomeDaDisciplina;
    this.nomeDoProfessor = nomeDoProfessor;
    this.quantidadeDeVagas = quantidadeDeVagas;
    this.mediaAprovacao = mediaAprovacao;
    
    nomesDosAlunos = new String[quantidadeDeVagas];
    notasDosAlunos = new float[quantidadeDeVagas];
  }

  /**
   * Método getter para retorno do nome da disciplina.
   * 
   * @return Retorna uma string contendo o nome da disciplina.
   */
  public String getNomeDisciplina()
  {
    // TODO
    return nomeDaDisciplina;
  }

  /**
   * Método setter para atribuir o nome da disciplina.
   * 
   * @param nomeDaDisciplina String contendo o nome da disciplina.
   */
  public void setNomeDisciplina(String nomeDaDisciplina)
  {
    // TODO
    this.nomeDaDisciplina = nomeDaDisciplina;
  }

  /**
   * Método getter para retornar o nome do professor responsável pela disciplina.
   * 
   * @return Retorna uma string contendo o nome do professor responsável pela disciplina.
   */
  public String getNomeProfessor()
  {
    // TODO
    return nomeDoProfessor;
  }

  /**
   * Método setter para atribuir o nome do professor responsável pela disciplina.
   * 
   * @param nome Nome do professor responsável pela disciplina.
   */
  public void setNomeProfessor(String nome)
  {
    // TODO
    nomeDoProfessor = nome;
  }

  /**
   * Método getter para retornar quantidade de vagas ofertadas pela disciplina.
   * 
   * @return Retorna um número inteiro que informa a quantidade de vagas ofertadas pela disciplina.
   */
  public int getQuantidadeDeVagas()
  {
    // TODO
    return quantidadeDeVagas;
  }

  /**
   * Método setter para definir quantidade de vagas ofertadas pela disciplina.
   * 
   * @param quantidadeDeVagas Número de vagas ofertadas pela disciplina.
   */
  public void setQuantidadeDeVagas(int quantidadeDeVagas)
  {
    // TODO
    this.quantidadeDeVagas = quantidadeDeVagas;
  }
  
  /**
   * Método setter para definir a média de aprovação da disciplina.
   * 
   * @param mediaAprovacao Média de aprovação da disciplina.
   */
  public void setMediaAprovacao(float mediaAprovacao)
  {
    // TODO
    this.mediaAprovacao = mediaAprovacao;
  }

  /**
   * Método getter para retornar a média de aprovação da disciplina.
   * 
   * @return Um número float que informa a média de aprovação da disciplina.
   */
  public float getMediaAprovacao()
  {
    // TODO
    return mediaAprovacao;
  }

  /**
   * Registra um aluno na disciplina com a respectiva nota.
   * 
   * @param nomeDoAluno String contendo o nome do aluno.
   * @param notaDoAluno Número de ponto-flutuante da nota do aluno.
   */
  public void registraAlunoComNota(String nomeDoAluno, float notaDoAluno)
  {
    // TODO
    if (matriculados < quantidadeDeVagas) {
        nomesDosAlunos[matriculados] = nomeDoAluno;
        notasDosAlunos[matriculados] = notaDoAluno;
        
        matriculados++;
    }
  }

  /**
   * Calcula e retorna a média aritmética de todas as notas dos alunos incluidos na disciplina.
   * 
   * @return Retorna a média aritmética de todas as notas da disciplina.
   */
  public float recuperarMediaTurma()
  {
    // TODO
    float media_turma = 0;
    
    if (matriculados > 0) 
    {
        for (int i = 0; i < matriculados; i++)
        {
            media_turma += notasDosAlunos[i];
        }
        media_turma /= matriculados;
    }
    
    return media_turma;
  }

  /**
   * Retorna verdadeiro caso a média de notas da turma for maior que a média de aprovação da disciplina.
   * 
   * @return Retorna se a turma inteira está aprovada ou não na disciplina.
   */
  public boolean turmaAprovada()
  {
    // TODO
    return recuperarMediaTurma() >= mediaAprovacao;
  }
}
