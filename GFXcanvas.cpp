#include <Adafruit_GFX.h>    // Biblioteca de gráficos
#include <Adafruit_ILI9341.h> // Biblioteca de display (por exemplo, ILI9341)

// Defina o pino de comunicação
#define TFT_CS     10
#define TFT_RST    9
#define TFT_DC     8

// Crie um objeto para o display
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

class GFXcanvas8 : public Adafruit_GFX {
public:
    uint8_t *buffer; ///< Raster data: no longer private, allow subclass access

    GFXcanvas8(uint16_t w, uint16_t h) : Adafruit_GFX(w, h) {
        buffer = (uint8_t *)malloc(w * h / 8);
    }

    ~GFXcanvas8() {
        if (buffer) {
            free(buffer);
        }
    }

    void clearBuffer() {
        memset(buffer, 0, _width * _height / 8);
    }

    void drawPixel(int16_t x, int16_t y, uint16_t color) override {
        if (x < 0 || x >= _width || y < 0 || y >= _height) return;

        int byteIndex = (y * _width + x) / 8;
        int bitIndex = x % 8;
        if (color) {
            buffer[byteIndex] |= (1 << bitIndex);
        } else {
            buffer[byteIndex] &= ~(1 << bitIndex);
        }
    }

    void display() {
        for (int y = 0; y < _height; y++) {
            for (int x = 0; x < _width; x++) {
                int byteIndex = (y * _width + x) / 8;
                int bitIndex = x % 8;
                uint16_t color = (buffer[byteIndex] & (1 << bitIndex)) ? ILI9341_WHITE : ILI9341_BLACK;
                tft.drawPixel(x, y, color);
            }
        }
    }
};

class GFXcanvas16 : public Adafruit_GFX {
public:
    uint16_t *buffer;

    GFXcanvas16(uint16_t w, uint16_t h) : Adafruit_GFX(w, h) {
        buffer = (uint16_t *)malloc(w * h * sizeof(uint16_t));
    }

    ~GFXcanvas16() {
        if (buffer) {
            free(buffer);
        }
    }

    void clearBuffer() {
        memset(buffer, 0, _width * _height * sizeof(uint16_t));
    }

    void drawPixel(int16_t x, int16_t y, uint16_t color) override {
        if (x < 0 || x >= _width || y < 0 || y >= _height) return;
        buffer[y * _width + x] = color;
    }

    void display() {
        for (int y = 0; y < _height; y++) {
            for (int x = 0; x < _width; x++) {
                uint16_t color = buffer[y * _width + x];
                tft.drawPixel(x, y, color);
            }
        }
    }
};

void setup() {
    // Iniciar comunicação com o display
    tft.begin();
    tft.setRotation(3); // Defina a rotação do display
    tft.fillScreen(ILI9341_BLACK);

    // Criar canvas com 240x320 pixels
    GFXcanvas16 canvas(240, 320);
    canvas.clearBuffer();

    // Desenhar algo no canvas
    canvas.drawPixel(120, 160, ILI9341_RED);

    // Exibir o canvas no display
    canvas.display();
}

void loop() {
    // A lógica do loop pode ser colocada aqui, se necessário
}
