int main() {
 
    int tempo, x,hora, minuto, segundo;
    x=3600;//horas em segundos
    scanf("%d", &tempo);
    hora = (tempo/x); 
    minuto = (tempo -(x*hora))/60;
    segundo = (tempo -(x*hora)-(minuto*60));
    printf("%d:%d:%d\n",hora,minuto,segundo);
 
    return 0;
}
