#ifndef __CIRCULAR_BUFFER_HPP__
#define __CIRCULAR_BUFFER_HPP__

template<typename T, size_t N>
class CircularBuffer {
    private:
        size_t _writeIndex;
        bool _allValuesSetted;
        T _data[N];
        size_t _getCount() { return (_allValuesSetted) ? N : _writeIndex; }
        size_t _getLastIndex() {
            if(isEmpty())
                return 0;
            return (_writeIndex == 0) ? N - 1 : _writeIndex - 1;
        }
        void _incWriteIndex() {
            if(_writeIndex == N - 1) {
                _writeIndex = 0;
                if(!_allValuesSetted)
                    _allValuesSetted = true;
                return;
            }
            _writeIndex++;
        }
    public:
        CircularBuffer() {}
        bool isEmpty() { return _getCount() == 0; }
        void clear() {
            if(isEmpty())
                return;
            size_t count = _getCount();
            _allValuesSetted = false;
            _writeIndex = 0;
            for(size_t i = 0; i < count; i++)
                _data[i] = 0;            
        }
        void add(T value) {
            _data[_writeIndex] = value;
            _incWriteIndex();
        }
        float avg() {
            if(isEmpty())
                return 0;
            T sum = 0;
            size_t count = _getCount();
            for(size_t i = 0; i < count; i++)
                sum += _data[i];
            return (float)sum / count;
        }
        T getLast() {
            if(isEmpty())
                return 0;
            return _data[_getLastIndex()];
        }
};
#endif
