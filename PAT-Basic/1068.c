//#include <iostream>
//#include <vector>
//#include <map>
//using namespace std;
//int main1086() {
//	int M,N,TOL;
//	scanf("%d %d %d",&M,&N,&TOL);
//	vector<int> v;
//	map<int , int >m;
//	int a[N][M];
//	for(int i=0; i<N; i++) for(int j=0; j<M; j++) 	{
//			scanf("%d",&a[i][j]);
//			m[a[i][j]]++;
//		}
//	int x,y;
//	for(int i=0; i<N; i++) {//���� �����Ǵ�һ��ʼ��N-1������
//		if(v.size()>1) break;
//		for(int j=0; j<M; j++) {//ͬ��  ���� Ҳ�����Ǵ�һ��ʼ��M-1������
//			if(m[a[i][j]]>1) continue;
//            //���涼��Ҫ�ж� �±��Ƿ��ڷ�Χ��
//			if(abs(a[i][j]-a[i-1][j-1])<=TOL && i-1>=0  && j-1>=0) continue;	   //����
//			if(abs(a[i][j]-a[i][j-1]) <=TOL &&j-1>=0) continue;	   //��
//			if(abs(a[i][j]-a[i+1][j-1]) <=TOL && i+1<N &&j-1>=0) continue;	   //����
//			if(abs(a[i][j]-a[i-1][j]) <=TOL&& i-1>=0 ) continue;   //�� ��
//			if(abs(a[i][j]-a[i-1][j+1]) <=TOL&& i-1>=0 &&j+1<M) continue;   //����
//			if(abs(a[i][j]-a[i][j+1]) <=TOL  &&j+1<M) continue;	   //��
//			if(abs(a[i][j]-a[i+1][j+1]) <=TOL && i+1<N &&j+1<M) continue;   //����
//			if(abs(a[i][j]-a[i+1][j]) <=TOL && i+1<N) continue;   //����
//			v.push_back(a[i][j]);
//			x=i+1;
//			y=j+1;
//		}
//	}
//	if(v.size()>1) cout<<"Not Unique";
//	else if(v.size()==1) printf("(%d, %d): %d",y,x,v[0]);
//	else  cout<<"Not Exist";
//	return 0;
//}
