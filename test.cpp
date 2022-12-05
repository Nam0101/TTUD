#include <bits/stdc++.h>
using namespace std;

typedef struct HocPhan
{
    string maHP;
    string tenHP;
    int soTC;
    float diem;
    HocPhan *next;
} HocPhan;

typedef struct SinhVien
{
    int maSV;
    string hoTen;
    HocPhan *danhSachHP;
    SinhVien *next;
} SinhVien;

void addSinhVien(SinhVien *&danhSachSV, SinhVien *sv)
{
    if (danhSachSV == NULL)
    {
        danhSachSV = sv;
    }
    else
    {
        SinhVien *p = danhSachSV;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = sv;
    }
}
void removeSinhVien(SinhVien *&danhSachSV, int maSV)
{
    if (danhSachSV == NULL)
    {
        return;
    }
    else
    {
        SinhVien *p = danhSachSV;
        if (p->maSV == maSV)
        {
            danhSachSV = p->next;
            delete p;
        }
        else
        {
            while (p->next != NULL && p->next->maSV != maSV)
            {
                p = p->next;
            }
            if (p->next != NULL)
            {
                SinhVien *q = p->next;
                p->next = q->next;
                delete q;
            }
        }
    }
}
void addHocPhan(HocPhan *&danhSachHP, HocPhan *hp)
{
    if (danhSachHP == NULL)
    {
        danhSachHP = hp;
    }
    else
    {
        HocPhan *p = danhSachHP;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = hp;
    }
}
void removeHocPhan(HocPhan *&danhSachHP, string maHP)
{
    if (danhSachHP == NULL)
    {
        return;
    }
    else
    {
        HocPhan *p = danhSachHP;
        if (p->maHP == maHP)
        {
            danhSachHP = p->next;
            delete p;
        }
        else
        {
            while (p->next != NULL && p->next->maHP != maHP)
            {
                p = p->next;
            }
            if (p->next != NULL)
            {
                HocPhan *q = p->next;
                p->next = q->next;
                delete q;
            }
        }
    }
}

void tinhDTB(SinhVien *sv)
{
    float tongDiem = 0;
    int tongTC = 0;
    HocPhan *p = sv->danhSachHP;
    while (p != NULL)
    {
        tongDiem += p->diem * p->soTC;
        tongTC += p->soTC;
        p = p->next;
    }
    cout << "Diem trung binh cua sinh vien " << sv->hoTen << " la: " << tongDiem / tongTC << endl;
}

SinhVien *getMaxDTB(SinhVien *danhSachSV)
{
    SinhVien *max = danhSachSV;
    SinhVien *p = danhSachSV;
    while (p != NULL)
    {
        if (p->danhSachHP != NULL)
        {
            float tongDiem = 0;
            int tongTC = 0;
            HocPhan *q = p->danhSachHP;
            while (q != NULL)
            {
                tongDiem += q->diem * q->soTC;
                tongTC += q->soTC;
                q = q->next;
            }
            if (tongDiem / tongTC > max->danhSachHP->diem)
            {
                max = p;
            }
        }
        p = p->next;
    }
    return max;
}

SinhVien *getMaxPoint(SinhVien *danhSachSV)
{
    SinhVien *max = danhSachSV;
    SinhVien *p = danhSachSV;
    while (p != NULL)
    {
        if (p->danhSachHP != NULL)
        {
            HocPhan *q = p->danhSachHP;
            while (q != NULL)
            {
                if (q->diem > max->danhSachHP->diem)
                {
                    max = p;
                }
                q = q->next;
            }
        }
        p = p->next;
    }
    return max;
}
void printDanhSachSinhVien(SinhVien *danhSachSV)
{
    SinhVien *p = danhSachSV;
    while (p != NULL)
    {
        cout << "-----------------------------------" << endl;
        cout << "Ma sinh vien: " << p->maSV << endl;
        cout << "Ho ten: " << p->hoTen << endl;
        cout << "Danh sach hoc phan: " << endl;
        HocPhan *q = p->danhSachHP;
        while (q != NULL)
        {
            cout << "\tMa hoc phan: " << q->maHP << endl;
            cout << "\tTen hoc phan: " << q->tenHP << endl;
            cout << "\tSo tin chi: " << q->soTC << endl;
            cout << "\tDiem: " << q->diem << endl;
            q = q->next;
        }
        cout << "-----------------------------------" << endl;
        p = p->next;
    }
}
// write a test case
int main()
{
    SinhVien *danhSachSV = NULL;
    SinhVien *sv1 = new SinhVien;
    sv1->maSV = 1;
    sv1->hoTen = "Nguyen Van A";
    sv1->danhSachHP = NULL;
    sv1->next = NULL;
    addSinhVien(danhSachSV, sv1);
    SinhVien *sv2 = new SinhVien;
    sv2->maSV = 2;
    sv2->hoTen = "Nguyen Van B";
    sv2->danhSachHP = NULL;
    sv2->next = NULL;
    addSinhVien(danhSachSV, sv2);
    SinhVien *sv3 = new SinhVien;
    sv3->maSV = 3;
    sv3->hoTen = "Nguyen Van C";
    sv3->danhSachHP = NULL;
    sv3->next = NULL;
    addSinhVien(danhSachSV, sv3);
    HocPhan *hp1 = new HocPhan;
    hp1->maHP = "HP1";
    hp1->tenHP = "Hoc phan 1";
    hp1->soTC = 3;
    hp1->diem = 8;
    hp1->next = NULL;
    addHocPhan(sv1->danhSachHP, hp1);
    HocPhan *hp2 = new HocPhan;
    hp2->maHP = "HP2";
    hp2->tenHP = "Hoc phan 2";
    hp2->soTC = 2;
    hp2->diem = 7;
    hp2->next = NULL;
    addHocPhan(sv1->danhSachHP, hp2);
    HocPhan *hp3 = new HocPhan;
    hp3->maHP = "HP3";
    hp3->tenHP = "Hoc phan 3";
    hp3->soTC = 4;
    hp3->diem = 9;
    hp3->next = NULL;
    addHocPhan(sv1->danhSachHP, hp3);
    HocPhan *hp4 = new HocPhan;
    hp4->maHP = "HP4";
    hp4->tenHP = "Hoc phan 4";
    hp4->soTC = 3;
    hp4->diem = 8;
    hp4->next = NULL;
    addHocPhan(sv2->danhSachHP, hp4);
    HocPhan *hp5 = new HocPhan;
    hp5->maHP = "HP5";
    hp5->tenHP = "Hoc phan 5";
    hp5->soTC = 2;
    hp5->diem = 7;
    hp5->next = NULL;
    addHocPhan(sv2->danhSachHP, hp5);
    HocPhan *hp6 = new HocPhan;
    hp6->maHP = "HP6";
    hp6->tenHP = "Hoc phan 6";
    hp6->soTC = 4;
    hp6->diem = 9;
    hp6->next = NULL;
    addHocPhan(sv2->danhSachHP, hp6);
    HocPhan *hp7 = new HocPhan;
    hp7->maHP = "HP7";
    hp7->tenHP = "Hoc phan 7";
    hp7->soTC = 3;
    hp7->diem = 8;
    hp7->next = NULL;
    addHocPhan(sv3->danhSachHP, hp7);
    printDanhSachSinhVien(danhSachSV);
}