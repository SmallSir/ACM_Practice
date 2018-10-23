typedef point  
{  
    int x;  
    int y;  
}RtPoint;  
  
typedef struct  
{  
    RtPoint sp; //裁剪窗口边界向量起点  
    RtPoint ep; //裁剪窗口边界向量终点  
}_RtInSide;  
  
static int _RtInSide(RtVector vector, RtPoint point) // 计算上面的V，vector为裁剪窗口边界向量，point为上面的p点  
{  
    return (vector.ep.x - vector.sp.x) * (point.y - vector.sp.y) - (vector.ep.y - vector.sp.y) * (point.x - vector.sp.x);  
}  
int rtPrunePSH(RtPoint* src, int num, RtPoint** dest, int* total)  
{  
    int i = 0, j = 0, k = -1, flag = 0;  
    RtPoint start, stop;//被剪裁多边形的边向量起点和终点  
    RtPoint sp, ep;//剪裁窗口边界向量的起点和终点  
    RtPoint* temp = NULL;  // temp保存针对某一裁剪窗口边界裁剪后的新坐标  
    temp = (RtPoint*)malloc(sizeof(RtPoint) * 3 * (*total));  
    if (temp == NULL) return -1;  
      
    sp = *(src + num - 1);  
  
    for ( i = 0; i < num; i++)//剪裁窗口  
    {  
        ep = *(src + i);  
          
        start = *((*dest) + *total - 1);  
        flag = _RtInSide(rtVector(sp, ep), start) > 0 ? 0 : 1; 
  
        for ( j = 0; j < *total; j++)//被剪裁的多边形  
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
                    (temp + k)->x = point[0];/*将交点放入新多边形*/   
                    (temp + k)->y = point[1];  
                }  
                k++;  
                *(temp + k) =  stop;/*将当前点pi放入新多边形*/   
            }  
            else  
            {
                if (0 != flag)/*前一个点在内侧吗？*/  
                {  
                    flag = 0;    
                    k++;  
                    CRtPoint<double> point;  // 同上面一样  
                    CRtPoint<int> st(sp.x, sp.y), et(ep.x, ep.y);                   
                    CRtLine<int> v1(st, et);  
                    st.SetData(start.x, start.y);  
                    et.SetData(stop.x, stop.y);  
                    CRtLine<int> v2(st, et);  
                    v2.Intersect(v1,point);  
                    (temp + k)->x = point[0];/*将交点放入新多边形*/   
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
