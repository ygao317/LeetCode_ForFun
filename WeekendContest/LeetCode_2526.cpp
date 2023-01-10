class DataStream {
private:
    int _val, _k, _cnt;
public:
    DataStream(int value, int k) {
        _val = value;
        _k = k; 
        _cnt = 0;
    }
    
    bool consec(int num) {
        if (num != _val){
            _cnt = 0;
            return false;
        }else{
            _cnt++;
            return _cnt >=_k; 
        }               
    }
};
