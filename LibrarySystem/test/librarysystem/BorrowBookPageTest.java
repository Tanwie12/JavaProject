/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit4TestClass.java to edit this template
 */
package librarysystem;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Enzo Maria
 */
public class BorrowBookPageTest {
    
    public BorrowBookPageTest() {
    }
    
    @BeforeClass
    public static void setUpClass() {
    }
    
    @AfterClass
    public static void tearDownClass() {
    }
    
    @Before
    public void setUp() {
    }
    
    @After
    public void tearDown() {
    }

    /**
     * Test of GetDate method, of class BorrowBookPage.
     */
    @Test
    public void testGetDate() {
        System.out.println("GetDate");
        String expResult = "";
        String result = BorrowBookPage.GetDate();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of GetAddedDate method, of class BorrowBookPage.
     */
    @Test
    public void testGetAddedDate() {
        System.out.println("GetAddedDate");
        String expResult = "";
        String result = BorrowBookPage.GetAddedDate();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of main method, of class BorrowBookPage.
     */
    @Test
    public void testMain() {
        System.out.println("main");
        String[] args = null;
        BorrowBookPage.main(args);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }
    
}
