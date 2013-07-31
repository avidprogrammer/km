#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

typedef long ARR_T;
#define ARR_SZ (sizeof(ARR_T))
#define ARR_SZ_Bt ((ARR_SZ * 8) - 1)
#define MAX_VAL (~(1<<ARR_SZ_Bt))
#define POS_BMSK MAX_VAL

//#define DEBUG

class BigNum
{
  public:
  long bitlen;
  long arrlen;
  ARR_T* arr;

  BigNum(long len)
  {
    bitlen = len;
    arrlen = ceil((float)len/(ARR_SZ_Bt));
    arr = new ARR_T [arrlen];
  }
  
  ~BigNum(void)
  {
    delete arr;
    bitlen = 0;
    arrlen = 0;
  }

  BigNum* operator +(BigNum* bn2)
  {
    long new_arr_len;
    new_arr_len = arrlen + 1;
    BigNum* bnr = new BigNum(len_to_bits(new_arr_len + 1));

    int co = 0;
    for (long i = 0; i < arrlen; i++)
    {
      bnr->arr[i] = arr[i] + bn2->arr[i] + co;
      co = 0;
      if (bnr->arr[i] < 0)
      {  
        co = 1;
        bnr->arr[i] &= POS_BMSK;
      }
    }
    bnr->arr[arrlen] = co;
    return bnr;
  }

  void read(void)
  {
    long idx = arrlen - 1;
    int val;
    int msb_bits = bitlen % (ARR_SZ_Bt);

    // Pack the bits into a long. 
    // signed datatype chosen as it helps in detection of overflow
    if (msb_bits)
    {
      while (msb_bits > 0)
      {
        scanf("%1d",&val);
        arr[idx] = (arr[idx] << 1) | val;
        msb_bits--;
      }
      idx--;
    }
    for(long i = idx; i >=0; i--)
    {
      arr[i] = 0;
      for(unsigned long j = 0; j < ARR_SZ_Bt; j++)
      {
        scanf("%1ld",&val);
        arr[i] = (arr[i] << 1) | val;
      }
    }
  }

  void write(void)
  {
    for (long i=arrlen-1; i>=0; i--)
      printf("i : %ld arr[i] %lu\n", i, arr[i]);
  }

  void get(long bit)
  {
    long idx = bit/ARR_SZ_Bt;
    long pos = bit % ARR_SZ_Bt;
    printf("%lu",(arr[idx] >> pos) & 0x1);
  }

  void set(long bit, int val)
  {
    long idx = bit/ARR_SZ_Bt;
    long pos = bit % ARR_SZ_Bt;
    if (val)
      arr[idx] = arr[idx] | 0x1 << pos;
    else
      arr[idx] = arr[idx] & ~(0x1 << pos);
  }

  private:
  long len_to_bits(long len)
  {
    return len * ARR_SZ_Bt;
  }

};

#ifdef DEBUG
static void test_init()
{
  int test_sz[] = {10, 64, 65};
  int resp_sz[] = {1, 1, 2};

  for (int i = 0; i < 3; i++)
  {
    BigNum* bn1 = new BigNum(test_sz[i]);
    if (bn1 -> arrlen == resp_sz[i] && bn1 ->bitlen == test_sz[i])
      cout << "Pass : Alloc size " << test_sz[i] << endl;
    else
    {
      cout << "Fail : Alloc size " << test_sz[i] << endl;
      cout << "Expected Size " << resp_sz[i] << "Actual " << bn1->arrlen << endl;
    }
    delete bn1;
  }
}  

static void add_verify(BigNum* bn1, BigNum* bn2, ARR_T *resp)
{
  BigNum *bnr = *bn1 + bn2;
  for (int i=0; i < bnr->arrlen; i++)
  {
    if (resp[i] != bnr->arr[i])
    {
      cout << "Fail add expected : " << resp[i] << "Actual : " << bnr->arr[i];
      cout << " i : " << i << endl;
      return;
    }
  }
  cout << "Pass add\n";
}

static void test_add()
{
  BigNum bn1 = BigNum(ARR_SZ_Bt + 1);
  BigNum bn2 = BigNum(ARR_SZ_Bt + 1);
  ARR_T res[5] = {0};

  // case 1
  cout << "Case 1\n";
  bn1.arr[0] = 1;
  bn1.arr[1] = 0;
  bn2.arr[0] = 2;
  bn2.arr[1] = 0;
  res[0] = 3;
  res[1] = 0;
  add_verify(&bn1, &bn2, res);

  // case 2
  cout << "Case 2\n";
  bn1.arr[0] = MAX_VAL;
  bn1.arr[1] = 0;
  bn2.arr[0] = 2;
  bn2.arr[1] = 0;
  res[0] = 1;
  res[1] = 1;
  add_verify(&bn1, &bn2, res);
  
  // case 3
  cout << "Case 3\n";
  bn1.arr[0] = MAX_VAL;
  bn1.arr[1] = MAX_VAL;
  bn2.arr[0] = MAX_VAL;
  bn2.arr[1] = MAX_VAL;
  res[0] = MAX_VAL - 1;
  res[1] = MAX_VAL;
  res[2] = 1;
  add_verify(&bn1, &bn2, res);
  BigNum* bnr = bn1 + &bn2;
  bnr->get(0);
  bnr->get(63);
  bnr->get(64);
  bnr->set(63, 0);
  bnr->set(64, 0);
  bnr->get(63);
  bnr->get(64);
}  

void test_cmds()
{
  BigNum bn1 = BigNum(ARR_SZ_Bt + 1);
  BigNum bn2 = BigNum(ARR_SZ_Bt + 1);

  // case 1
  cout << "Case 1\n";
  bn1.arr[0] = MAX_VAL;
  bn1.arr[1] = MAX_VAL;
  bn2.arr[0] = MAX_VAL;
  bn2.arr[1] = MAX_VAL;
  BigNum* bn3 = bn1 + &bn2;

  cout << bn3->arr[2] << bn3->arr[1] << bn3->arr[0];
}  
#endif

int main()
{
#ifdef DEBUG
  //test_init();
  test_add();
  test_cmds();
#else  
  long N, Q, bit;
  int val;
  char cmd[6];
  BigNum *bn1, *bn2, *bnr=NULL;

  cin >> N >> Q;
  bn1 = new BigNum(N);
  bn2 = new BigNum(N);
  bn1->read();
  bn2->read();

  for (long i=0; i<Q; i++)
  {
    scanf("%s", cmd);
    cmd[5] = '\0';
    if (cmd[0] == 's')
    {  
      scanf("%ld %d", &bit, &val);
      if (cmd[4] == 'a')
        bn1->set(bit, val);
      else
        bn2->set(bit, val);
      if (bnr)
        delete bnr;
      bnr = NULL;
    }
    else
    {
      scanf("%ld", &bit);
      if (bnr)
        bnr->get(bit);
      else
      {
        bnr = *bn1 + bn2;
        bnr->get(bit);
      }

    }
  }
#endif
  return 0;
}
