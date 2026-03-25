
class Matrix{
    public:
        int rows,cols;
        double m1[100][100],m2[100][100],add_ans[100][100],sub_ans[100][100];
        Matrix();
        Matrix(int rows,int cols);
        Matrix(const Matrix &m);
        void input();
        void printMatrix();
        void addition();
        void subtraction();
        void GaussianElimination();
        void backSubstitution();
        void partialPivot(int k);
};