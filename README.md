<h1>PRINTF</h1>

Criação de uma versão simplificada da função <b>printf()</b> da LibC, com a mesma prototipagem.
A ft_printf() imprime corretamente no terminal os tipos:
<ul>
  <li><b>%c:</b> character;</li>
  <li><b>%s:</b> string;</li>
  <li><b>%p:</b> endereço de um ponteiro em formato hexadecimal;</li>
  <li><b>%d</b> ou <b>%i:</b> número inteiro em base 10;</li>
  <li><b>%u:</b> número inteiro em base 10 (sem sinal);</li>
  <li><b>%x</b> ou <b>%X:</b> número em formato hexadecimal, em letras minúsculas (%x), ou maiúsculas (%X);</li>
  <li><b>%%:</b> o próprio sinal de porcentagem;</li>
</ul>

<h3>CONCEITOS</h3>

Nesse projeto, o maior desafio foi entender e implementar uma <b>função variádica</b>, como a <b>printf</b>, que pode receber um número diferente de argumentos a cada chamada.
Para criar esse tipo de função, foi utilizada a biblioteca <b>stdarg.h</b>, que inclui o objeto <b>va_list</b> e as funções <b>va_start</b>, <b>va_arg</b> e <b>va_end</b>.
