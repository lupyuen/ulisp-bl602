# Simulate BL602 with uLisp WebAssembly

What if we...

1.  Compile the __uLisp Interpreter to WebAssembly__...

1.  Use the WebAssembly version of uLisp to __simulate BL602 in a Web Browser__...

    (Including GPIO, I2C, SPI, Display Controller, Touch Controller, LoRaWAN... [Similar to this](https://lupyuen.github.io/pinetime-rust-mynewt/articles/simulator))

1.  Integrate the __BL602 Emulator with Blockly__...

1.  To allow embedded developers to __preview their BL602 Blockly Apps in the Web Browser__?

Let's try this out here with the [__`wasm` branch of `ulisp-bl602`__](https://github.com/lupyuen/ulisp-bl602/tree/wasm)

[(Follow the Twitter Thread for updates)](https://twitter.com/MisterTechBlog/status/1393554618924212224)

# BL602 uLisp Library (Compiled for WebAssembly)

A version of the Lisp programming language for BL602 RISC-V boards.

Read the article...

- [__uLisp and Blockly on PineCone BL602 RISC-V Board__](https://lupyuen.github.io/articles/lisp)

uLisp was ported to BL602 from ESP32 Arduino...

https://github.com/technoblogy/ulisp-esp

BL602 uLisp Firmware `sdk_app_ulisp` is located here...

https://github.com/lupyuen/bl_iot_sdk/tree/ulisp/customer_app/sdk_app_ulisp

For more information about uLisp...

http://www.ulisp.com/show?21T5
