/*
 * Sistemas de Telecomunicacoes 
 *          2019/2020
 */
package calculator;

/**
 *
 * @author lflb@fct.unl.pt
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
        // First, checks what to do with the operand
        switch (first_pair.operation) {
            case IDLE_OPERATION: // First operand
                first_pair.operand = new_operand;
                break;
            case '+':   // Calculate pending addition
                first_pair.operand += new_operand;
                break;
            case '=':
                break;
            default:    // Error - operation not supported
                first_pair.reset();
                return false;
        }
        // After, memorizes pending operation
        first_pair.operation = new_operation;
        return true;
    }

    // Class local variables
    private final Pair first_pair;
}
