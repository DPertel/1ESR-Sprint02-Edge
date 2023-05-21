SPRINT 02

- Deivison Pertel – RM 550803
- Eduardo Akira Murata – RM 98713
- Guilherme Jacob Soares da Costa – RM 84581
- Fabrizio El Ajouri Romano – RM 550410
- Wesley Souza de Oliveira – RM 97874

---

# Controle de Umidade do Solo com Display LCD e Buzzer

Este é um código Arduino que utiliza um display LCD e um buzzer para controlar a umidade do solo. O código utiliza um potenciômetro para medir a umidade do solo e exibir as informações no display LCD, além de emitir um som de alerta caso a umidade esteja abaixo de um valor desejado.

[--> Link do Projeto no Tinkercad <--](https://www.tinkercad.com/things/0cUHGss6yek-copy-of-teste-checkpoint2/editel?sharecode=Hy3Slu059cY18oS0kFhULp3vhJcTJ3gMQOjysahD46E)

---

## Componentes Utilizados

Display LCD (utilizando a biblioteca LiquidCrystal)
Buzzer
Sensor de umidade (potenciômetro)

---

## Configuração
Antes de iniciar o loop principal do programa, a função setup() é chamada para realizar as configurações iniciais. O código contém as seguintes etapas de configuração:

Inicialização do display LCD: A biblioteca LiquidCrystal é utilizada para criar um objeto lcd que representa o display. Os pinos do Arduino conectados ao display são especificados na criação do objeto LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2). Neste caso, os pinos são configurados como: RS (pino 12), E (pino 11), D4 (pino 10), D5 (pino 5), D6 (pino 4) e D7 (pino 3).

Configuração dos pinos: Os pinos do buzzer (buzzer) e do sensor de luminosidade (lightSensorPin) são configurados como saída e entrada, respectivamente, utilizando as funções pinMode(buzzer, OUTPUT) e pinMode(lightSensorPin, INPUT).

Inicialização da comunicação serial: A função Serial.begin(9600) é chamada para iniciar a comunicação serial com uma taxa de transmissão de dados de 9600 bits por segundo.

---

## Loop Principal

O programa entra no loop principal, a função loop(), que é executada continuamente até que o Arduino seja desligado.

Leitura da umidade do solo: O valor do sensor de luminosidade (potenciômetro) é lido utilizando a função analogRead(lightSensorPin). O valor lido é armazenado na variável potValue.

Conversão do valor lido: O valor lido pelo sensor é mapeado de um intervalo de 0 a 1023 para um intervalo de 0 a 100, utilizando a função map(potValue, 1023, 0, 100, 0). O resultado é armazenado na variável lightValue, que representa a umidade do solo em percentual.

Exibição no display LCD: Com base no valor da umidade (lightValue), o programa verifica em qual faixa de umidade o solo se encontra e exibe a mensagem correspondente no display LCD. Se a umidade estiver abaixo de 60%, o buzzer é acionado. Se a umidade estiver entre 60% e 70%, o buzzer é desligado. Para umidade acima de 70%, o buzzer também é desligado. As mensagens exibidas no display LCD são atualizadas de acordo com a faixa de umidade encontrada.

Limpeza do display: Após a exibição das informações no display LCD, há um atraso de 3 segundos (delay(3000)) e o display é limpo utilizando a função lcd.clear().

O programa então retorna ao início do loop principal e repete o processo indefinidamente.

---

## Observações
Certifique-se de que as bibliotecas necessárias estejam instaladas no seu ambiente de desenvolvimento Arduino. Para este código, a biblioteca "LiquidCrystal" é utilizada para controlar o display LCD.

Além disso, é importante verificar se os componentes estão corretamente conectados aos pinos do Arduino de acordo com as configurações especificadas no código.

Este código é um exemplo simples de controle de umidade do solo utilizando um sensor de luminosidade como referência. Pode ser necessário ajustar os valores de referência e as faixas de umidade de acordo com as necessidades do seu projeto.

---