typedef point  
{  
    int x;  
    int y;  
}RtPoint;  
  
typedef struct  
{  
    RtPoint sp; //�ü����ڱ߽��������  
    RtPoint ep; //�ü����ڱ߽������յ�  
}_RtInSide;  
  
static int _RtInSide(RtVector vector, RtPoint point) // ���������V��vectorΪ�ü����ڱ߽�������pointΪ�����p��  
{  
    return (vector.ep.x - vector.sp.x) * (point.y - vector.sp.y) - (vector.ep.y - vector.sp.y) * (point.x - vector.sp.x);  
}  
int rtPrunePSH(RtPoint* src, int num, RtPoint** dest, int* total)  
{  
    int i = 0, j = 0, k = -1, flag = 0;  
    RtPoint start, stop;//�����ö���εı����������յ�  
    RtPoint sp, ep;//���ô��ڱ߽������������յ�  
    RtPoint* temp = NULL;  // temp�������ĳһ�ü����ڱ߽�ü����������  
    temp = (RtPoint*)malloc(sizeof(RtPoint) * 3 * (*total));  
    if (temp == NULL) return -1;  
      
    sp = *(src + num - 1);  
  
    for ( i = 0; i < num; i++)//���ô���  
    {  
        ep = *(src + i);  
          
        start = *((*dest) + *total - 1);  
        flag = _RtInSide(rtVector(sp, ep), start) > 0 ? 0 : 1; 
  
        for ( j = 0; j < *total; j++)//�����õĶ����  
        {     
            stop = *((*dest) + j);  
            if (_RtInSide(rtVector(sp, ep), stop) <= 0)
            {  
                if (flag == 0)
                {  
                    flag = 1;
                    k++;  
                    CRtPoint<double> point;  
                    CRtPoint<int> st(sp.x, sp.y), et(ep.x, ep.y);               
                    CRtLine<int> v1(st, et);
                    st.SetData(start.x, start.y);  
                    et.SetData(stop.x, stop.y);
                    CRtLine<int> v2(st, et);   
                    v2.Intersect(v1,point);  
                    (temp + k)->x = point[0];/*����������¶����*/   
                    (temp + k)->y = point[1];  
                }  
                k++;  
                *(temp + k) =  stop;/*����ǰ��pi�����¶����*/   
            }  
            else  
            {
                if (0 != flag)/*ǰһ�������ڲ���*/  
                {  
                    flag = 0;    
                    k++;  
                    CRtPoint<double> point;  // ͬ����һ��  
                    CRtPoint<int> st(sp.x, sp.y), et(ep.x, ep.y);                   
                    CRtLine<int> v1(st, et);  
                    st.SetData(start.x, start.y);  
                    et.SetData(stop.x, stop.y);  
                    CRtLine<int> v2(st, et);  
                    v2.Intersect(v1,point);  
                    (temp + k)->x = point[0];/*����������¶����*/   
                    (temp + k)->y = point[1];  
                }  
            }  
            start = stop;        }  
  
        sp = ep;  
        *total = k + 1; 
        memcpy(*dest, temp, sizeof(RtPoint) * (*total));  
        k = -1;  
    }  
  
    return 0;  
}  
