/**
 * A classe Matriz deve ser capaz de amazenar uma valores reais em 
 * uma matriz 2D de dimensões arbitrárias. Além disso, ela deve ser 
 * capaz de realizar operações em sua matriz com outras matrizes
 * e números escalares.
 */
public class Matriz
{
   /**
   * Constroi uma matriz de dimensões X e Y contendo os valores especificados no parametro "valores".
   * 
   * O construtor deve construir uma matriz de dimensões X por Y
   * preenchendo-a com os valores especificados no parâmetro "valores".
   * Caso as dimensões sejam menores ou iguais a zero,
   * será construida uma matriz de dimensão 0x0 sem elementos.
   * 
   * @param dimensaoX Tamanho da matriz na dimensão X.
   * @param dimensaoY Tamanho da matriz na dimensão Y.
   * @param valores Valores dos elementos da matriz.
   */
   
  private int x;
  private int y;
  private float[][] elementos;
   
  public Matriz(int dimensaoX, int dimensaoY, final float[][] valores)
  {
    // TODO
    if (dimensaoX < 0 || dimensaoY < 0)
        dimensaoX = dimensaoY = 0;
        
    x = dimensaoX;
    y = dimensaoY;
    
    elementos = new float[x][y];
    
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++)
            elementos[i][j] = valores[i][j];
    }
  }

  /**
   * Retorna dimensão X da matriz.
   * 
   * @return Retorna inteiro informando dimensão X da matriz.
   */
  public int getDimensaoX()
  {
    // TODO
    return x;
  }

  /**
   * Retorna dimensão Y da matriz.
   * 
   * @return Retorna inteiro informando dimensão Y da matriz.
   */
  public int getDimensaoY()
  {
    // TODO
    return y;
  }

  /**
   * Calcula a multiplicação desta matriz por uma outra matriz.
   * 
   * A multiplicação de matrizes é realizada multiplicando-se a linha
   * de uma matriz pela coluna de outra de acordo com a regra [1]. Por
   * fim, o método deve retornar uma nova matriz contendo o resultado
   * da multiplicação.
   * 
   * [1] https://brasilescola.uol.com.br/matematica/multiplicacao-matrizes.htm
   * 
   * @param m Matriz que será usada na multiplicação.
   * @return Deve-se retornar uma nova matriz contendo o resultado da multiplicação.
  **/
  public Matriz multiplica(final Matriz o)
  {
    // TODO
    Matriz matriz = new Matriz(x, y, elementos);
    
    if(matriz.getDimensaoY() == o.getDimensaoX()) {
        float[][] result_m = new float[matriz.getDimensaoX()][o.getDimensaoY()];
        
        for(int i = 0; i < matriz.getDimensaoX(); i++) {
            for(int j = 0; j < o.getDimensaoY(); j++) {
                result_m[i][j] = 0;
                
                for(int r = 0; r < o.getDimensaoX(); r++)
                    result_m[i][j] += matriz.getElemento(i, r) * o.getElemento(r, j);
            }
        }
        
        Matriz result_M = new Matriz(matriz.getDimensaoX(), o.getDimensaoY(), result_m);
        
        return result_M;
    }
    else
        return matriz;
  }

  /**
   * Calcula a multiplicação desta matriz por um número escalar.
   * 
   * Este método calcula a multiplicação elemento a elemento pelo número
   * escalar passado como parâmetro.
   * 
   * @param v Número escalar usado na multiplicação.
   * @return Deve-se retornar uma nova matriz contendo o resultado da multiplicação.
   */
  public Matriz multiplicaElementos(float v)
  {
    // TODO
    Matriz matriz = new Matriz(x, y, elementos);
    
    float[][] result_m = new float[matriz.getDimensaoX()][matriz.getDimensaoY()];
    
    for(int i = 0; i < matriz.getDimensaoX(); i++) {
        for(int j = 0; j < matriz.getDimensaoY(); j++)
            result_m[i][j] = matriz.getElemento(i, j) * v;
    }
    
    Matriz result_M = new Matriz(matriz.getDimensaoX(), matriz.getDimensaoY(), result_m);
    
    return result_M;
  }

  /**
   * Calcula a soma desta matriz com outra matriz.
   * 
   * Calcula a soma desta matriz com outra matriz desde que ambas as
   * matrizes possuam a mesma dimensão. Caso as dimensões das matrizes não
   * sejam as mesmas, deve-se retornar esta matriz sem qualquer alteração
   * em seus valores.
   * 
   * @param m Matriz usada na soma com outra matriz.
   * @return Retorna uma nova matriz contendo o resultado da soma
   * ou esta matriz sem qualquer alteração em seus valores.
   */
  public Matriz soma(final Matriz o)
  {
    // TODO
    Matriz matriz = new Matriz(x, y, elementos);
    
    if(matriz.getDimensaoX() == o.getDimensaoX() && matriz.getDimensaoY() == o.getDimensaoY()) {
        float[][] result_m = new float[matriz.getDimensaoX()][matriz.getDimensaoY()];
    
        for(int i = 0; i < matriz.getDimensaoX(); i++) {
            for(int j = 0; j < matriz.getDimensaoY(); j++)
                result_m[i][j] = matriz.getElemento(i, j) + o.getElemento(i, j);
        }
    
        Matriz result_M = new Matriz(matriz.getDimensaoX(), matriz.getDimensaoY(), result_m);
        
        return result_M;
    }
    else
        return matriz;
  }

  /**
   * Calcula a soma de cada elemento desta matriz com o escalar informado.
   * 
   * @param v Escalar a ser usado na soma.
   * @return Retorna uma nova matriz contendo o resultado da soma de cada
   * elemento com o escalar informado.
   */
  public Matriz somaElementos (float v)
  {
    // TODO
    Matriz matriz = new Matriz(x, y, elementos);
    
    float[][] result_m = new float[matriz.getDimensaoX()][matriz.getDimensaoY()];
    
    for(int i = 0; i < matriz.getDimensaoX(); i++) {
        for(int j = 0; j < matriz.getDimensaoY(); j++)
            result_m[i][j] = matriz.getElemento(i, j) + v;
    }
    
    Matriz result_M = new Matriz(matriz.getDimensaoX(), matriz.getDimensaoY(), result_m);
    
    return result_M;
  }

  /**
   * Retorna valor do elemento nas coordenadas [x,y].
   * 
   * @param x Coordenada X do elemento a ser retornado.
   * @param y Coordenada Y do elemento a ser retornado.
   * @return Retorna valor do elemento nas coordenadas [x,y].
   */
  public float getElemento(int x, int y)
  {
    // TODO
    return elementos[x][y];
  }

  /**
   * Define um novo valor para o elemento nas coordenadas [x,y].
   * 
   * @param x Coordenada X do elemento a ser alterado.
   * @param y Coordenada Y do elemento a ser alterado.
   * @param v Novo valor do elemento.
   */
  public void setElemento(int x, int y, float v)
  {
    // TODO
    elementos[x][y] = v;
  }
}
