// maneja el arduino que controla los sensores su funcion es detectar 
// si el balon entro en la celda correcta y ademas en cual entro, en un valor de 0 a 73
// recibe la orden de iniciar el sensado, cada valor tiene 2 sensores con lo que se mide el tiempo, mide la diferencia en las medidas y envia el tiempo
// envia el valor de la celda, espera un tiempo determinado y envia que ningun balon entro 
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
// se recibe la orden de iniciar sensado 
// al activar S11 se inicia un temporizador que se apaga al activarse S12 
// se envia tiempo y numero de celda 
// si no se recibe balon se envia 0
