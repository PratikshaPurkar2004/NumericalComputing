class Matrix{
    public:
        int rows;
        int cols;
        double mat[100][100]; 
        Matrix(int rows,int cols);
        Matrix(const Matrix &m);
        void input();
        void display();
        void addition(Matrix &m);
        void subtraction(Matrix &m);
        void GaussianElimination();
};