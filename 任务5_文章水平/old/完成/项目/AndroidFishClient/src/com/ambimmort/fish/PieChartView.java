package com.ambimmort.fish;

import net.droidsolutions.droidcharts.awt.Font;
import net.droidsolutions.droidcharts.awt.Rectangle2D;
import net.droidsolutions.droidcharts.core.ChartFactory;
import net.droidsolutions.droidcharts.core.JFreeChart;
import net.droidsolutions.droidcharts.core.data.DefaultPieDataset;
import net.droidsolutions.droidcharts.core.data.PieDataset;
import net.droidsolutions.droidcharts.core.plot.PiePlot;
import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Rect;
import android.os.Handler;
import android.util.AttributeSet;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnTouchListener;
import android.widget.Toast;

public class PieChartView extends View  {
	/** The view bounds. */   
    private final Rect mRect = new Rect();   
    /** The user interface thread handler. */   
    private final Handler mHandler;  
    /*context*/
    private Context context = null ;
    /**
     * dataset to draw with the guesture
     */
    private DefaultPieDataset ds  = null ;  
    private JFreeChart chart = null ;
   
    public PieChartView(Context context) {   
        this(context, null);   
         createDataset(); 
        this.context = context ;
       
    }   
       
    public PieChartView(Context context, AttributeSet attrs) {   
        this(context, attrs, 0);  
        createDataset(); 
        this.context = context ;
       
    }   
       
    public PieChartView(Context context, AttributeSet attrs, int defStyle) {   
        super(context, attrs, defStyle);   
        mHandler = new Handler();   
        createDataset(); 
        this.context = context ;
       
    }   
   
    @Override   
    protected void onDraw(Canvas canvas) {   
        super.onDraw(canvas); 
        canvas.getClipBounds(mRect); 
        chart = createChart();
        chart.draw(canvas, new Rectangle2D.Double(0, 0, mRect.width(), mRect.height()));   
    }   
   
    /**  
     * Schedule a user interface repaint.  
     */   
    public void repaint() {   
        mHandler.post(new Runnable() {   
            public void run() {   
                invalidate();   
            }   
        });   
    }   
   
    private PieDataset createDataset() {   
        ds = new DefaultPieDataset();        
        ds.setValue("fill", 10);
        ds.setValue("unfill", 90);       
        return ds;   
    }   
   
    private JFreeChart createChart() {   
        // create the chart...   
    	 
        final JFreeChart chart = ChartFactory.createPieChart(null, ds, false, false, false);   
   
        Paint black = new Paint(Paint.ANTI_ALIAS_FLAG);   
        black.setColor(Color.BLACK);   
        chart.setBackgroundPaint(black);   
        chart.setBorderVisible(false);   
   
        Paint color0 = new Paint(Paint.ANTI_ALIAS_FLAG);   
        color0.setColor(Color.YELLOW);   
        Paint color1 = new Paint(Paint.ANTI_ALIAS_FLAG);   
        color1.setColor(Color.BLACK);
       
               
           
        final PiePlot plot = (PiePlot)chart.getPlot();   
        plot.setBackgroundPaint(black);   
        plot.setSectionPaint("fill", color0);   
        plot.setSectionPaint("unfill", color1);   
        
        
           
        // 设置默认字体    
        plot.setLabelFont(new Font());         
        // 不显示文本    
        plot.setLabelGenerator(null);   
        // 设置开始角度为3点钟方向    
        plot.setStartAngle(0); 
       
         
        return chart;   
    }	

   
    public void setAngle(int proportion)
    {
    	ds.setValue("fill", proportion);
		ds.setValue("unfill", 100-proportion);
		invalidate(); 
    }
	 



}
