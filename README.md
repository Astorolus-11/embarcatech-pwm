# Projeto utilizando PWM para manipular um LED e Servo Motor

## 1. Propósito
O objetivo desse projeto é manipular um LED e um Servo Motor, alternando o ângulo de 0° a 180° do Servo Motor e analisar seu comportamento atribuindo as mesmas configurações a um LED.

## 2. Vídeo de demonstração

https://www.dropbox.com/scl/fi/dewt6rv8yuze43312nd9f/V-deo-do-WhatsApp-de-2025-02-11-s-18.35.05_3c12face.mp4?rlkey=pu2beel17vr3n72wmoqmtf125&st=i4gdmnsj&dl=0


## 3. Funcionalidades
1. Inicialmente o Servo Motor está na posição 180° e então percorre até o 0°;
2. Com um intervalo de 5000ms ele vai de 0° para 90°;
3. Com mais um intervalo de 5000ms ele vai de 90° para 180°;
4. Por ultimo ele fica alternando entre 0° e 180°.
   
   (OBS: O LED possui as mesmas configurações, será possível observar que o LED muda de intensidade) 



## 4. Pré-requisitos
1. Ter o [Pico SDK](https://github.com/raspberrypi/pico-sdk) instalado na máquina;
2. Ter o [ARM GNU Toolchain](https://developer.arm.com/Tools%20and%20Software/GNU%20Toolchain) instalado;
3. Ter o [Visual Studio Code](https://code.visualstudio.com/download) instalado;
4. Ter este repositório clonado na sua máquina;
5. Ter as seguintes extensões instaladas no seu VS Code para o correto funcionamento:
- [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools);
- [CMake](https://marketplace.visualstudio.com/items?itemName=twxs.cmake);
- [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools);
- [Raspberry Pi Pico](https://marketplace.visualstudio.com/items?itemName=raspberry-pi.raspberry-pi-pico);

##  5. Como executar o projeto e simular:
1. Clonar o repositório: https://github.com/Astorolus-11/embarcatech-pwm
2. Abrir a pasta clonada através do import project:

   ![image](https://github.com/user-attachments/assets/9ea528e1-0253-4cf8-b6c6-8532be0fc1b4)
   
4. Abrir o arquivo diagram.json:

   ![image](https://github.com/user-attachments/assets/028cb510-04e5-4d61-9484-523f9c3b5579)
5. Para executar na placa clique em Run que está localizada no rodapé do vscode (A placa precisa já está conectada e com o BootSel ativado):

   ![image](https://github.com/user-attachments/assets/36b14dce-1309-4f0c-a7f3-3cd7edb2b336)
   
  # A placa utilizada foi a BitDogLab, com o Raspberry Pi Pico W RP2040, disponibilizada pela Embarcatech.
  ![WhatsApp Image 2025-02-09 at 18 50 34](https://github.com/user-attachments/assets/b61bbb99-e33a-4585-aeee-581cc2e549b7)



  # Pronto! já está tudo pronto para testar o projeto!

