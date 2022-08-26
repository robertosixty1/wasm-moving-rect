typedef long Pixel;

Pixel rgba(long r, long g, long b, long a)
{
    return (a << (3 * 8)) |
           (b << (2 * 8)) |
           (g << (1 * 8)) |
           (r << (0 * 8));
}

#define WIDTH  640
#define HEIGHT 420
static Pixel display[WIDTH*HEIGHT] = {0};

Pixel* get_display(void)
{
    return display;
}

long get_display_width(void)
{
    return WIDTH;
}

long get_display_height(void)
{
    return HEIGHT;
}

long max(long a, long b)
{
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

long min(long a, long b)
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

long clamp(long x, long low, long high)
{
    return min(max(low, x), high);
}

void fill_rect(long x0, long y0, long w, long h, Pixel pixel)
{
    long x1 = clamp(x0, 0, (WIDTH - 1));
    long x2 = clamp(x0 + w - 1, 0, (WIDTH - 1));
    long y1 = clamp(y0, 0, (HEIGHT - 1));
    long y2 = clamp(y0 + h - 1, 0, (HEIGHT - 1));

    for (int y = y1; y <= y2; ++y) {
        for (int x = x1; x <= x2; ++x) {
            display[y*WIDTH+x] = pixel;
        }
    }
}

long x = 0;
long y = 0;
#define DEFAULT_VELOCITY 2
long vel_x = DEFAULT_VELOCITY;
long vel_y = DEFAULT_VELOCITY;

#define RECT_WIDTH  100
#define RECT_HEIGHT 100
void update()
{
    for (int i = 0; i < WIDTH*HEIGHT; ++i) display[i] = rgba(18, 18, 18, 255);
    fill_rect(x, y, 100, 100, rgba(255, 221, 51, 255));

    if ((x + RECT_WIDTH)  > WIDTH  || x < 0) vel_x = -vel_x;
    if ((y + RECT_HEIGHT) > HEIGHT || y < 0) vel_y = -vel_y;

    x += vel_x;
    y += vel_y;
}
