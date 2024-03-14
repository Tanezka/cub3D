#include "./mlx/mlx.h"
#include "image.h"
#include <stdio.h>
#include <stdlib.h>

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color; // resmin bir pikseline renk atar
}

int exit_game(t_data *img)
{
    mlx_destroy_image(img->mlx, img->img);
    mlx_destroy_window(img->mlx, img->mlx_win);
    exit(0);
    return (0);
}

int key_down(int keycode, t_data *img)
{
    printf("key down: %d\n", keycode);
    if (keycode == 53)
    {
        exit_game(img);
    }
    return (0);
}

int main()
{
    t_data img;
    void *mlx_win2; 
    void *mlx2;

    img.img_path = "./png/supersonic.png";
    if ((img.mlx = mlx_init()) == NULL) // mlx kütüphanesini başlatır ve başlatıldıysa bir adres döner aksi halde NULL döner
        printf("mlx init failed\n");
    mlx2 = img.mlx;
    mlx_win2 = mlx_new_window(mlx2, 800, 600, "Hello World!"); // pencere oluşturur ve oluşturulduysa bir adres döner aksi halde NULL döner
    if (mlx_win2 != NULL)
    {
        if (mlx_clear_window(mlx2, mlx_win2) != 0) // pencereyi siyah arka planla temizler
            printf("clear failed\n");
        if (mlx_destroy_window(mlx2, mlx_win2) != 0) // pencereyi kapatır ve bellekten siler
       		printf("destroy failed\n");
    }
    if ((img.mlx_win = mlx_new_window(img.mlx, 1000, 1000, "cub3D")) == NULL)
        printf("window failed\n");
/*     if ((img.img = mlx_new_image(img.mlx, 1920, 1080)) == NULL) // resim oluşturur
        printf("image failed\n"); */
    img.img = mlx_png_file_to_image(img.mlx, img.img_path, &img.width, &img.height); // resmi dosyadan alır
/*     if ((img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian)) == NULL) // resmin başlangıç adresini alır
        printf("data addr failed\n"); */
    printf("bpp: %d\n", img.bits_per_pixel); // bir piksel rengini temsil etmek için gereken bit sayısı 1 piksel 4 byte = 32bit
    printf("ll: %d\n", img.line_length); // resmin bir satırının byte cinsinden uzunluğu 1920 * 4
    printf("e: %d\n", img.endian); // resmin endianını verir
/*     for (int x = 960; x < 1920; x++)
    {
        for (int y = 540; y < 1080; y++)
        {
            my_mlx_pixel_put(&img, x, y, 0x0000FF00); // resme yeşil piksel koyar
        }
    } */
    mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0); // resmi pencereye koyar
    mlx_hook(img.mlx_win, 2, 1L << 0, key_down, &img); // klavye tuşuna basıldığında key_down fonksiyonunu çağırır klavyeyi dinler
    mlx_hook(img.mlx_win, 17, 1L << 17, exit_game, &img); // pencereyi kapatma tuşuna basıldığında key_down fonksiyonunu çağırır
    mlx_loop(img.mlx); // pencereyi açık tutar
    return (0);
}

/* Endian Nedir?
Endian, bir bilgisayarın bellek ve veri depolamada byte sırasını belirler. İki ana endian türü vardır:

Big Endian: Büyük endian'da, bir sayının en önemli byte'ı (MSB) en düşük bellek adresinde saklanır.
Little Endian: Küçük endian'da, bir sayının en az önemli byte'ı (LSB) en düşük bellek adresinde saklanır.
Örnek:

1234 sayısını ondalık olarak ele alalım.

Big Endian:
MSB: 1 (1000)
LSB: 4 (4)
Bellek: 0x12 0x34

Little Endian:
MSB: 4 (4)
LSB: 1 (1000)
Bellek: 0x34 0x12 

endian : 0 = sever X küçük endian, 1 = büyük endian
endian : macos'ta işe yaramaz, istemci ve grafik çerçeve aynı endian'a sahiptir*/