hello

class vector{
    private:
        int sz;
        double* elem;
        void copy(const vector& arg){
            for(int i=0;i<arg.sz;++i)elem[i] = arg.elem[i];
        }
        void copy2(const vector& arg,double* p){
            for(int i=0;i<arg.sz;++i)p[i] = arg.elem[i];
        }
    public:
        explicit vector(int n):sz(n),elem(new double[n]){}
        int size()const{return sz;}
        double get(int ind){return elem[ind];}
        void set(int ind,double val){elem[ind]=val;}
        double& operator[](int n){return elem[n];}
        vector(const vector& arg):sz(arg.sz),elem(new double[arg.sz]){
            copy(arg);
        }
        void print(){
            for(int i=0;i<sz;++i)cout<<elem[i]<<" ";
            cout<<endl;
        }

        vector& operator=(const vector& a){
            double* p  = new double[a.sz];
            copy2(a,p);
            delete[] elem;
            elem = p;
            sz = a.sz;
            return *this;
        }
};

