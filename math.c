 /** 
 * @author bulargy.j.bai  
* @创建时间：Mar 9, 2015 
 * @描述：  */ 
public class Math{  
 
public static int divide(int x,int y) { 
return x/y; 
} 

 public static int multiple(int x,int y) {
return x*y;
} 
}
/** 
 * @author bulargy.j.bai  
* @创建时间：Mar 9, 2015
 * @描述：  */ 
public class MathTest {   @BeforeClass 
 public static void setUpBeforeClass() throws Exception {
} 
  @AfterClass 
 public static void tearDownAfterClass() throws Exception {
 } 
  @Test 
 public void testDivide() {   fail("Not yet implemented");  } 
  @Test 
 public void testMultiple() {   fail("Not yet implemented");  
 } 
 }
package org.bj.util; 
import org.junit.runner.RunWith; import org.junit.runners.Suite; 
import org.junit.runners.Suite.SuiteClasses; /** 
 * @author bulargy.j.bai  * @创建时间：Mar 9, 2015  * @描述：  */ 
@RunWith(Suite.class) 
@SuiteClasses({MathTest.class, 
 
  MathTestAnother.class})
public class Util4Suite {
 }
//@Ignore("忽略乘法测试")  @Test 
 
public void testMultiple(){
 
assertEquals(result,Math.multiple(faciend,multiplicator)); 
 
}
@Parameters 
 public static Collection multipleValues() {
return Arrays.asList(new Object[][] {
 {3, 2, 6 },  
 {4, 3, 12 }, 
{5, 7, 35 },
{6, 7, 42 },
 {11, 7, 77 },
{25, 4, 100 },
{34, 3, 102 },
{21, 5, 105 },
{11, 22, 242 },
{8, 9, 72 }});
}
