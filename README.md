# PS1b
Image Encryption with FibLFSR


In PS1b, the FibLFSR class from PS1a is used to encrypt and decrypt .jpg images by applying a pseudo-random bit stream to each pixel’s RGB values. The program reads an input .jpg file using SFML, then for each pixel, it generates an 8-bit number with FibLFSR::generate(8) and XORs it with the red, green, and blue channels. Because XOR is a symmetric operation, running the program again on the output image with the same seed restores the original. This demonstrates how simple linear feedback shift registers can be used for lightweight, reversible encryption based on bitwise operations and pseudo-random number generation.

<img width="825" height="490" alt="screenshot2" src="https://github.com/user-attachments/assets/e46dec7a-086c-4bd3-9131-5216ee644ebc" />
<img width="778" height="486" alt="screenshot" src="https://github.com/user-attachments/assets/f0c36d3b-8359-4081-be27-d36ebaebb24c" />

