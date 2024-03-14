import java.util.Scanner;

public class SortIMC

{
  public static void main(String[] args)
  {
    float[] peso = new float[3];
    float[] altura = new float[3];
    float[] imc = new float[3];
    float aux;
    int i, j;
    
    Scanner scan = new Scanner(System.in);
    
    for(i = 0; i < 3; i++) {
        peso[i] = Float.parseFloat(scan.next());
        altura[i] = Float.parseFloat(scan.next());
        
        imc[i] = peso[i]/(altura[i]*altura[i]);
    }
    
    for(i = 0; i < 3; i++) {
        for(j = i+1; j < 3; j++) {
            if (imc[i] > imc[j]) {
                aux = imc[i];
                imc[i] =imc[j];
                imc[j] = aux;
            }
        }
    }
    
    for(i = 0; i < 3; i++) {
        System.out.printf("%f", imc[i]);
        if(i < 2)
            System.out.print(", ");
    }
  }
}