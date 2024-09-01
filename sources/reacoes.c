#include "../headers/reacoes.h"
#define RESET       "\033[0m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"
#define TEXT_COLOR_256(x)    "\033[38;5;" x "m"


void imprimeReacao(char caractereEmpilha){
    switch (caractereEmpilha){
    case 'A':
        printf(TEXT_COLOR_256("58") " .d888888      888888ba                                          88888888b oo                                .d888888                                                 \n");
        printf("d8'    88      88    `8b                                         88                                         d8'    88                                                 \n");
        printf("88aaaaa88a    a88aaaa8P' .d8888b. .d8888b. .d8888b. .d8888b.    a88aaaa    dP .d8888b. .d8888b. dP    dP    88aaaaa88a 88d8b.d8b. .d8888b. 88d888b. .d8888b. .d8888b. \n");
        printf("88     88      88        88'  `88 88'  `\"\" 88'  `88 88'  `88     88        88 88'  `\"\" 88'  `88 88    88    88     88  88'`88'`88 88'  `88 88'  `88 88'  `88 88'  `88 \n");
        printf("88     88      88        88.  .88 88.  ... 88.  .88 88.  .88     88        88 88.  ... 88.  .88 88.  .88    88     88  88  88  88 88.  .88 88       88.  .88 88.  .88 \n");
        printf("88     88      dP        `88888P' `88888P' `88888P8 `88888P'     dP        dP `88888P' `88888P' `88888P'    88     88  dP  dP  dP `88888P8 dP       `8888P88 `88888P8 \n");
        printf("                                                                                                                                                         .88          \n");
        printf("                                                                                                                                                     d8888P          \n");
        break;
    case 'V':
        printf(TEXT_COLOR_256("12")" .d888888                                                     .d88888b           dP   dP                        dP     dP                                      \n");
        printf("d8'    88                                                     88.    \"'          88   88                        88     88                                      \n");
        printf("88aaaaa88a    88d888b. .d8888b. .d8888b. .d8888b. .d8888b.    `Y88888b. .d8888b. 88 d8888P .d8888b. dP    dP    88    .8P .d8888b. 88d888b. .d8888b. 88d888b. \n");
        printf("88     88     88'  `88 88'  `88 88'  `\"\" 88'  `88 88'  `88          `8b 88'  `88 88   88   88'  `88 88    88    88    d8' 88'  `88 88'  `88 88'  `88 88'  `88 \n");
        printf("88     88     88.  .88 88.  .88 88.  ... 88.  .88 88.  .88    d8'   .8P 88.  .88 88   88   88.  .88 88.  .88    88  .d8P  88.  .88 88.  .88 88.  .88 88       \n");
        printf("88     88     88Y888P' `88888P' `88888P' `88888P8 `88888P'     Y88888P  `88888P' dP   dP   `88888P' `88888P'    888888'   `88888P8 88Y888P' `88888P' dP       \n");
        printf("              88                                                                                                                   88                         \n");
        printf("              dP                                                                                                                   dP                         \n");
        break;
    case 'E':
        printf(".d888888      888888ba                                         .8888b  oo                               888888ba                                               \n");
        printf("d8'    88     88    `8b                                         88   \"                                   88    `8b                                             \n");
        printf("88aaaaa88a    a88aaaa8P' .d8888b. .d8888b. .d8888b. .d8888b.    88aaa  dP .d8888b. .d8888b. dP    dP    a88aaaa8P' 88d888b. .d8888b. 88d888b. .d8888b. .d8888b. \n");
        printf("88     88      88        88'  `88 88'  `\"\" 88'  `88 88'  `88    88     88 88'  `\"\" 88'  `88 88    88     88   `8b. 88'  `88 88'  `88 88'  `88 88'  `\"\" 88'  `88 \n");
        printf("88     88      88        88.  .88 88.  ... 88.  .88 88.  .88    88     88 88.  ... 88.  .88 88.  .88     88    .88 88       88.  .88 88    88 88.  ... 88.  .88 \n");
        printf("88     88      dP        `88888P' `88888P' `88888P8 `88888P'    dP     dP `88888P' `88888P' `88888P'     88888888P dP       `88888P8 dP    dP `88888P' `88888P8\n");
        printf("                                                                                                 \n");
        printf("                                                                                                 \n");
        break;
    case 'R':
        printf(TEXT_COLOR_256("64") "dP     dP                .d888888                                            888888ba           oo                  dP          .8888b                     dP                                     .d888888           \n");
        printf("88     88               d8'    88                                            88    `8b                              88          88   \"                     88                                    d8'    88           \n");
        printf("88     88 88d8b.d8b.    88aaaaa88a 88d888b. .d8888b. 88d8b.d8b. .d8888b.    a88aaaa8P' dP    dP dP 88d8b.d8b.       88 88d888b. 88aaa  .d8888b. .d8888b. d8888P .d8888b. dP    dP    .d8888b.    88aaaaa88a 88d888b. \n");
        printf("88     88 88'`88'`88    88     88  88'  `88 88'  `88 88'`88'`88 88'  `88     88   `8b. 88    88 88 88'`88'`88       88 88'  `88 88     88ooood8 Y8ooooo.   88   88'  `88 88    88    88'  `88    88     88  88'  `88 \n");
        printf("Y8.   .8P 88  88  88    88     88  88       88.  .88 88  88  88 88.  .88     88     88 88.  .88 88 88  88  88       88 88    88 88     88.  ...       88   88   88.  .88 88.  .88    88.  .88    88     88  88       \n");
        printf("`Y88888P' dP  dP  dP    88     88  dP       `88888P' dP  dP  dP `88888P8     dP     dP `88888P' dP dP  dP  dP       dP dP    dP dP     `88888P' `88888P'   dP   `88888P' `88888P'    `88888P'    88     88  dP\n");
        break;
    case 'X':
        printf(TEXT_COLOR_256("196")   ".d888888      888888ba                                          88888888b                    dP                dP oo             dP dP dP \n");
        printf(TEXT_COLOR_256("202")   "d8'    88      88    `8b                                         88                          88                88                88 88 88 \n");
        printf(TEXT_COLOR_256("214")   "88aaaaa88a    a88aaaa8P' .d8888b. .d8888b. .d8888b. .d8888b.    a88aaaa    dP.  .dP 88d888b. 88 .d8888b. .d888b88 dP dP    dP    88 88 88 \n");
        printf(TEXT_COLOR_256("228")   "88     88      88        88'  `88 88'  `\"\" 88'  `88 88'  `88     88         `8bd8'  88'  `88 88 88'  `88 88'  `88 88 88    88    dP dP dP \n");
        printf(TEXT_COLOR_256("228")   "88     88      88        88.  .88 88.  ... 88.  .88 88.  .88     88         .d88b.  88.  .88 88 88.  .88 88.  .88 88 88.  .88 \n");
        printf(TEXT_COLOR_256("214")   "88     88      dP        `88888P' `88888P' `88888P8 `88888P'     88888888P dP'  `dP 88Y888P' dP `88888P' `88888P8 dP `88888P'    oo oo oo \n");
        printf(TEXT_COLOR_256("202")   "                                                                                    88                                                     \n");
        printf(TEXT_COLOR_256("196")   "                                                                                    dP\n");
        break;
    case 'S':
        printf(TEXT_COLOR_256("178") ".d888888      888888ba                                          .8888b oo                               dP     dP oo                                               \n");
        printf("d8'    88      88    `8b                                        88                                      88     88                                                 \n");
        printf("88aaaaa88a    a88aaaa8P' .d8888b. .d8888b. .d8888b. .d8888b.    88aaa  dP .d8888b. .d8888b. dP    dP    88    .8P dP .d8888b. .d8888b. .d8888b. .d8888b. .d8888b. \n");
        printf("88     88      88        88'  `88 88'  `\"\" 88'  `88 88'  `88    88     88 88'  `\"\" 88'  `88 88    88    88    d8' 88 Y8ooooo. 88'  `\"\" 88'  `88 Y8ooooo. 88'  `88 \n");
        printf("88     88      88        88.  .88 88.  ... 88.  .88 88.  .88    88     88 88.  ... 88.  .88 88.  .88    88  .d8P  88       88 88.  ... 88.  .88       88 88.  .88 \n");
        printf("88     88      dP        `88888P' `88888P' `88888P8 `88888P'    dP     dP `88888P' `88888P' `88888P'    888888'   dP `88888P' `88888P' `88888P' `88888P' `88888P8\n");
        break;
    case 'C':
        printf(TEXT_COLOR_256("213")" .d888888      888888ba                                         .d888888         dP                   oo                            \n");
        printf("d8'    88      88    `8b                                        d8'    88        88                                                 \n");
        printf("88aaaaa88a    a88aaaa8P' .d8888b. .d8888b. .d8888b. .d8888b.    88aaaaa88a .d888b88 .d8888b. .d8888b. dP .d8888b. .d8888b. dP    dP \n");
        printf("88     88      88        88'  `88 88'  `\"\" 88'  `88 88'  `88    88     88  88'  `88 88'  `88 88'  `\"\" 88 88'  `\"\" 88'  `88 88    88 \n");
        printf("88     88      88        88.  .88 88.  ... 88.  .88 88.  .88    88     88  88.  .88 88.  .88 88.  ... 88 88.  ... 88.  .88 88.  .88 \n");
        printf("88     88      dP        `88888P' `88888P' `88888P8 `88888P'    88     88  `88888P8 `88888P' `88888P' dP `88888P' `88888P' `88888P' \n");
        break;
    case 'F':
        printf( TEXT_COLOR_256("46")" .d888888      a88888b.          dP                                                           88888888b                                           dP                            \n");
        printf( "d8'    88     d8'   `88          88                                                           88                                                  88                            \n");
        printf( "88aaaaa88a    88        .d8888b. 88 .d8888b. 88d888b. .d8888b. .d8888b. .d8888b. .d8888b.    a88aaaa    .d8888b. dP   .dP .d8888b. 88d888b. .d888b88 .d8888b. .d8888b. dP    dP \n");
        printf( "88     88     88        88'  `88 88 88'  `88 88'  `88 88'  `88 88'  `\"\" 88'  `88 88'  `88     88        Y8ooooo. 88   d8' 88ooood8 88'  `88 88'  `88 88ooood8 88'  `88 88    88 \n");
        printf( "88     88     Y8.   .88 88.  .88 88 88.  .88 88       88.  .88 88.  ... 88.  .88 88.  .88     88              88 88 .88'  88.  ... 88       88.  .88 88.  ... 88.  .88 88.  .88 \n");
        printf( "88     88      Y88888P' `88888P' dP `88888P' dP       `88888P8 `88888P' `88888P8 `88888P'     88888888P `88888P' 8888P'   `88888P' dP       `88888P8 `88888P' `88888P' `88888P' \n");
        break;
    case 'B':
        printf(CYAN " .d888888      888888ba                                          a88888b.                                                                         888888ba                    dP                dP dP                         \n");
        printf("d8'    88      88    `8b                                        d8'   `88                                                                         88    `8b                   88                88 88                         \n");
        printf("88aaaaa88a    a88aaaa8P' .d8888b. .d8888b. .d8888b. .d8888b.    88        .d8888b. 88d8b.d8b. .d8888b. .d8888b. .d8888b. dP    dP    .d8888b.    a88aaaa8P' .d8888b. 88d888b. 88d888b. dP    dP 88 88d888b. .d8888b. 88d888b. \n");
        printf("88     88      88        88'  `88 88'  `\"\" 88'  `88 88'  `88    88        88'  `88 88'`88'`88 88ooood8 88'  `\"\" 88'  `88 88    88    88'  `88     88   `8b. 88'  `88 88'  `88 88'  `88 88    88 88 88'  `88 88'  `88 88'  `88 \n");
        printf("88     88      88        88.  .88 88.  ... 88.  .88 88.  .88    Y8.   .88 88.  .88 88  88  88 88.  ... 88.  ... 88.  .88 88.  .88    88.  .88     88    .88 88.  .88 88       88.  .88 88.  .88 88 88    88 88.  .88 88       \n");
        printf("88     88      dP        `88888P' `88888P' `88888P8 `88888P'     Y88888P' `88888P' dP  dP  dP `88888P' `88888P' `88888P' `88888P'    `88888P8     88888888P `88888P' dP       88Y8888' `88888P' dP dP    dP `88888P8 dP\n");
        break;
    case 'P':
        printf(TEXT_COLOR_256("235")" .d888888      888888ba                                          88888888b            oo   dP   oo                                     888888ba           oo       dP             .d88888b  oo          oo            dP                     \n");
        printf("d8'    88      88    `8b                                         88                        88                                          88    `8b                   88             88.    \"'                           88                     \n");
        printf("88aaaaa88a    a88aaaa8P' .d8888b. .d8888b. .d8888b. .d8888b.    a88aaaa    88d8b.d8b. dP d8888P dP dP    dP    dP    dP 88d8b.d8b.    a88aaaa8P' dP    dP dP .d888b88 .d8888b.    `Y88888b. dP 88d888b. dP .d8888b. d8888P 88d888b. .d8888b. \n");
        printf("88     88      88        88'  `88 88'  `\"\" 88'  `88 88'  `88     88        88'`88'`88 88   88   88 88    88    88    88 88'`88'`88     88   `8b. 88    88 88 88'  `88 88'  `88          `8b 88 88'  `88 88 Y8ooooo.   88   88'  `88 88'  `88 \n");
        printf("88     88      88        88.  .88 88.  ... 88.  .88 88.  .88     88        88  88  88 88   88   88 88.  .88    88.  .88 88  88  88     88     88 88.  .88 88 88.  .88 88.  .88    d8'   .8P 88 88    88 88       88   88   88       88.  .88 \n");
        printf("88     88      dP        `88888P' `88888P' `88888P8 `88888P'     88888888P dP  dP  dP dP   dP   dP `88888P'    `88888P' dP  dP  dP     dP     dP `88888P' dP `88888P8 `88888P'     Y88888P  dP dP    dP dP `88888P'   dP   dP       `88888P'\n");
        break;
    case 'D':
        printf(TEXT_COLOR_256("88") " .d888888                                                     888888ba                                        dP                     \n");
        printf("d8'    88                                                     88    `8b                                       88                     \n");
        printf("88aaaaa88a    88d888b. .d8888b. .d8888b. .d8888b. .d8888b.    88     88 .d8888b. .d8888b. .d8888b. 88d888b. d8888P .d8888b. dP    dP \n");
        printf("88     88     88'  `88 88'  `88 88'  `\"\" 88'  `88 88'  `88    88     88 88ooood8 88'  `\"\" 88'  `88 88'  `88   88   88'  `88 88    88 \n");
        printf("88     88     88.  .88 88.  .88 88.  ... 88.  .88 88.  .88    88    .8P 88.  ... 88.  ... 88.  .88 88    88   88   88.  .88 88.  .88 \n");
        printf("88     88     88Y888P' `88888P' `88888P' `88888P8 `88888P'    8888888P  `88888P' `88888P' `88888P8 dP    dP   dP   `88888P' `88888P' \n");
        printf("              88                                                                                                                      \n");
        printf("              dP                                                                                                                      \n");
        break;
    case 'G':
        printf(TEXT_COLOR_256("5") " .d888888      888888ba                                          88888888b                                                                         \n");
        printf("d8'    88      88    `8b                                         88                                                                                 \n");
        printf("88aaaaa88a    a88aaaa8P' .d8888b. .d8888b. .d8888b. .d8888b.    a88aaaa    88d888b. .d8888b. 88d888b. .d8888b. .d8888b. .d8888b. .d8888b. dP    dP \n");
        printf("88     88      88        88'  `88 88'  `\"\" 88'  `88 88'  `88     88        88'  `88 88'  `88 88'  `88 88'  `88 Y8ooooo. Y8ooooo. 88'  `88 88    88 \n");
        printf("88     88      88        88.  .88 88.  ... 88.  .88 88.  .88     88        88    88 88.  .88 88       88.  .88       88       88 88.  .88 88.  .88 \n");
        printf("88     88      dP        `88888P' `88888P' `88888P8 `88888P'     88888888P dP    dP `8888P88 dP       `88888P' `88888P' `88888P' `88888P' `88888P' \n");
        printf("                                                                                         .88                                                        \n");
        printf("                                                                                     d8888P\n");
        break;
    default:
        break;
    }
    printf(RESET);
}