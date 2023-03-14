/*
 * Sistemas de Telecomunicacoes 
 *          2019/2020
 */
package calculator;

/**
 *
 * @author lflb@fct.unl.pt   &&   nobrega
 */
public class Calc_State {

    public final char IDLE_OPERATION = ' ';

    private class Pair {

        /**
         * Constructor - run when "new Pair()" is used
         */
        private Pair() {
            operand = 0;
            operation = IDLE_OPERATION;
        }

        /**
         * Resets the state to the default values
         */
        private void reset() {
            operand = 0;
            operation = IDLE_OPERATION;
        }

        public long operand;
        public char operation;
    }

    /**
     * Constructor - run when "new Calc_State()" is used
     */
    public Calc_State() {
        first_pair = new Pair();
        buffer_A = new Pair();
        buffer_B = new Pair();
        buffer_C = new Pair();
        buffer_Flag = new Pair();
    }

    public char last_operation() {
        /* Returns the last operation */
        return first_pair.operation;
    }

    public long last_operand() {
        /* Returns the last operation */
        return first_pair.operand;
    }

    /**
     * Resets the state to the default values
     */
    public void reset() {
        first_pair.reset();
    }

    /**
     * Configures first_pair depending on the stage of the operation
     *
     * In order to have precedences a "second_pair" object will be needed...
     *
     * @param new_operand
     * @return true if success; false if error
     */
    public boolean execute_or_push_operation(long new_operand, char new_operation) {
        
        if(first_pair.operation == '+' && new_operation == '*' && buffer_Flag.operand == 0){
            buffer_A.operation = first_pair.operation;
            buffer_A.operand = first_pair.operand;
            buffer_B.operation = new_operation;
            buffer_B.operand = new_operand;
            buffer_Flag.operand = 1;
            first_pair.reset();
            
            return true;
        }    
        
        if(buffer_Flag.operand == 1){
            if(new_operation=='='){
                buffer_C.operation = new_operation;
                buffer_C.operand = new_operand;
                
                first_pair.operand = buffer_B.operand * buffer_C.operand;
                first_pair.operand +=  buffer_A.operand;
                first_pair.operation = '=';
                
                buffer_A.reset();
                buffer_B.reset();
                buffer_C.reset();
                buffer_Flag.reset();
                
                return true;
                
            } else {
                buffer_C.operand = new_operand;
                buffer_C.operation = new_operation;
                
                buffer_B.operand *= buffer_C.operand;
                buffer_B.operation = buffer_C.operation;
                first_pair.reset();
                buffer_C.reset();
                
                return true;
            }
        } else {
        switch (first_pair.operation) {
            case IDLE_OPERATION: // First operand
                first_pair.operand = new_operand;
                break;
            case '+':   // Calculate pending addition
                first_pair.operand += new_operand;
                break;
            case '*':  // Calculaye pending multiplicatin
                first_pair.operand *= new_operand;
                break;
            case '=':
                break;
            default:    // Error - operation not supported
                first_pair.reset();
                return false;
        }
        // After, memorizes pending operation
        first_pair.operation = new_operation;    
        }
        return true;
    }
    // Class local variables
    private final Pair first_pair;
    private final Pair buffer_A;
    private final Pair buffer_B;
    private final Pair buffer_C;
    private final Pair buffer_Flag;
    
    
}
