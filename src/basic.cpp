#include "alfons/alfons.h"
#include "alfons/atlas.h"
#include "alfons/font.h"
#include "alfons/fontManager.h"
#include "alfons/textBatch.h"
#include "alfons/textShaper.h"

#include "logger.h"

#include "dejavu.h"

#define TEXT_SIZE 20

using namespace alfons;


class TestRenderer : public MeshCallback, public TextureCallback {
public:

    void drawGlyph(const Quad& box, const AtlasGlyph& glyph) override {

    }
    void drawGlyph(const Rect& rect, const AtlasGlyph& glyph) override {
        log("drawGlyph %d %d %d %d", rect.x1, rect.y1, rect.x2, rect.y2);

    }

    void addTexture(AtlasID id, uint16_t textureWidth, uint16_t textureHeight) override {
        log("addTexture %d", id);
    }
    void addGlyph(AtlasID id, uint16_t gx, uint16_t gy, uint16_t gw, uint16_t gh,
                  const unsigned char* src, uint16_t padding) override {
        log("addGlyph %d - %d,%d / %dx%d", id, gx, gy, gw, gh);

        static const char* symbols = "@%#x+=:-.  ";

        int h = gh;
        int w = gw;
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                printf("%c", symbols[src[y*w + x]/24]);
            }
            printf("\n");
        }
    }
};

TestRenderer renderer;
FontManager fontMan;
GlyphAtlas atlas(renderer, 256, 2);
TextBatch batch(atlas, renderer);
TextShaper shaper;

std::shared_ptr<Font> font;

int main(int argc, char *argv[]) {

    font = fontMan.addFont("default", InputSource(reinterpret_cast<const char*>(dejavu_data), dejavu_size), TEXT_SIZE);

    auto layout = shaper.shape(font, "Eß hatte aber alle Welt einerlei Zünge und Sprache.");

    batch.draw(layout, 0, 0);

    return 0;
}
