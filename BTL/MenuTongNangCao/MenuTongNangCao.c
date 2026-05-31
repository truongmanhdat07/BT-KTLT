#include "MenuTongNangCao.h"

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hidecursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void showcursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void hien_thi_loading() {
    system("cls");
    system("color 0A");
    
    int chieu_rong = 85;
    char *dong1 = "		   DANG KHOI DONG HE THONG";
    int len1 = strlen(dong1);
    int space1 = (chieu_rong - len1) / 2;
    printf("\n\n\n\n\n\n\n\n\n\n%*s%s\n\n", space1, "", dong1);
    
    int width = 40;
    for (int i = 0; i <= 100; i++) {
        int filled = i * width / 100;
        printf("\r%*s	  [", space1, "");
        for (int j = 0; j < filled; j++) printf("%c", 219);
        for (int j = filled; j < width; j++) printf("%c", 176);
        printf("] %3d%%", i);
        fflush(stdout);
        
        if (i == 100) {
            system("color 0F");
            Beep(1000, 100);
        }
        Sleep(15);
    }
    
    char *dong_cuoi = " 		Hoan tat! Nhan ENTER de vao Menu";
    int len_cuoi = strlen(dong_cuoi);
    int space_cuoi = (chieu_rong - len_cuoi) / 2;
    printf("\n\n%*s%s", space_cuoi, "", dong_cuoi);
    
    while (getch() != 13);
    system("color 0A");
}

void in_menu(int lua_chon_hien_tai) {
    gotoxy(0, 0);  
    printf("\n");
	printf("  |===========================================================|\n");
	printf("  |              Bai Tap Lon - Ky Thuat Lap Trinh             |\n");
	printf("  |                           NHOM 1                	      |\n");
	printf("  |===========================================================|\n\n");

    char *danh_sach_bai[] = {
        "",
        " 1. Chay bai E1", " 2. Chay bai E2", " 3. Chay bai E3",
        " 4. Chay bai E4", " 5. Chay bai E5", " 6. Chay bai F2",
        " 7. Chay bai F3", " 8. Chay bai F4", " 9. Chay bai F5",
        "10. Chay bai F6", "11. Chay bai F7", "12. Chay bai F8",
        "13. Thoat chuong trinh"
    };

    printf("  Su dung mui ten LEN/XUONG de di chuyen, an ENTER de chon.\n");
    printf("  HOAC nhap so (1-13) de chon truc tiep.\n\n");

    for (int i = 1; i <= 13; i++) {
        char buffer[80];
        if (i == lua_chon_hien_tai) {
            sprintf(buffer, "\t   ==> [ %s ] <==", danh_sach_bai[i]);
        } else {
            sprintf(buffer, "\t         %s", danh_sach_bai[i]);
        }
        printf("%-70s\n", buffer);   
    }
    printf("\n =============================================================\n");
}

void run_with_escape(const char *exe_path, const char *working_dir) {
    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    char cmd[512];
    snprintf(cmd, sizeof(cmd), "\"%s\"", exe_path);
    
    if (!CreateProcess(NULL, cmd, NULL, NULL, FALSE, 0, NULL, working_dir, &si, &pi)) {
        printf("Loi: Khong the chay %s (ma loi: %lu)\n", exe_path, GetLastError());
        system("pause");
        return;
    }
    
    while (1) {
        DWORD exit_code;
        if (GetExitCodeProcess(pi.hProcess, &exit_code) && exit_code != STILL_ACTIVE) {
            break;
        }
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            TerminateProcess(pi.hProcess, 0);
            printf("\n\n>>> Da huy bai tap.\n");
            printf(" Nhan phim bat ky de ve Menu.\n");
            system("pause>nul");
            break;
        }
        Sleep(100);
    }
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

void chay_bai(int luachon) {
    system("color 07");
    system("cls");
    showcursor();

    char ten_bai[10];
    char duong_dan[256];
    char thu_muc[256];
    
    switch (luachon) {
        case 1: sprintf(ten_bai, "E1"); sprintf(duong_dan, "..\\E1\\E1.exe"); sprintf(thu_muc, "..\\E1"); break;
        case 2: sprintf(ten_bai, "E2"); sprintf(duong_dan, "..\\E2\\E2.exe"); sprintf(thu_muc, "..\\E2"); break;
        case 3: sprintf(ten_bai, "E3"); sprintf(duong_dan, "..\\E3\\E3.exe"); sprintf(thu_muc, "..\\E3"); break;
        case 4: sprintf(ten_bai, "E4"); sprintf(duong_dan, "..\\E4\\E4.exe"); sprintf(thu_muc, "..\\E4"); break;
        case 5: sprintf(ten_bai, "E5"); sprintf(duong_dan, "..\\E5\\E5.exe"); sprintf(thu_muc, "..\\E5"); break;
        case 6: sprintf(ten_bai, "F2"); sprintf(duong_dan, "..\\F2\\F2.exe"); sprintf(thu_muc, "..\\F2"); break;
        case 7: sprintf(ten_bai, "F3"); sprintf(duong_dan, "..\\F3\\F3.exe"); sprintf(thu_muc, "..\\F3"); break;
        case 8: sprintf(ten_bai, "F4"); sprintf(duong_dan, "..\\F4\\F4.exe"); sprintf(thu_muc, "..\\F4"); break;
        case 9: sprintf(ten_bai, "F5"); sprintf(duong_dan, "..\\F5\\F5.exe"); sprintf(thu_muc, "..\\F5"); break;
        case 10: sprintf(ten_bai, "F6"); sprintf(duong_dan, "..\\F6\\F6.exe"); sprintf(thu_muc, "..\\F6"); break;
        case 11: sprintf(ten_bai, "F7"); sprintf(duong_dan, "..\\F7\\F7.exe"); sprintf(thu_muc, "..\\F7"); break;
        case 12: sprintf(ten_bai, "F8"); sprintf(duong_dan, "..\\F8\\F8.exe"); sprintf(thu_muc, "..\\F8"); break;
        case 13:
            printf("\nKet thuc chuong trinh!\n");
            exit(0);
        default: return;
    }
    
    printf("\n=================== DANG CHAY BAI %s ================\n", ten_bai);
    printf(">>> Nhan phim ESC de quay lai Menu.\n\n");
    
    run_with_escape(duong_dan, thu_muc);
    
    printf("\n");
    system("pause");
    system("color 0A");
    system("cls");
    hidecursor();
}

void xu_ly_phim_so(int phim_dau) {
    int so = phim_dau - '0';
    if (so == 1) {
        Sleep(500);
        if (_kbhit()) {
            int phim_hai = getch();
            if (phim_hai >= '0' && phim_hai <= '9') {
                so = so * 10 + (phim_hai - '0');
            }
        }
    }
    if (so >= 1 && so <= 13) {
        chay_bai(so);
    } else {
        Beep(500, 100);
    }
}
