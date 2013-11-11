import java.awt.image.BufferedImage;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import javax.imageio.ImageIO;

public class TERMESImageProcessing 
 {
	/**
	 * Converts a valid byte array to a buffered image
	 * @param input the byte array
	 * @return a buffferedImage
	 */
	public static BufferedImage convertByteArrayToImage(byte[] input)
	{
		ByteArrayInputStream bis = new ByteArrayInputStream(input);
		BufferedImage image = null;
		try 
		{
			image = ImageIO.read(bis);
			if(image == null)
				throw new IOException("The resulting image is null (convertByteArrayToImage)");
		} 
		catch (IOException e) 
		{
			// TODO Auto-generated catch block
			System.err.println("Conversion form byte[] to BufferedImage not succesful");
			e.printStackTrace();
		}
		
		return image;
	}
	
	/**
	 * Converts a BufferedImage a byte array
	 * Throws an IOExcetion if the resulting byte array is null
	 * @param input the bufferedImage
	 * @return a byte array representation of the image
	 */
	public static byte[] convertImageToByteArray(BufferedImage input)
	{
		ByteArrayOutputStream baos = new ByteArrayOutputStream();
		byte[] imageInByte = null;
		
		try 
		{
			ImageIO.write(input, "jpg", baos);
			baos.flush();
			imageInByte = baos.toByteArray();
			baos.close();
			if(imageInByte == null)
				throw new IOException("The resulting byte array is null (convertImageToByteArray)");
		} 
		catch (IOException e) 
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		return imageInByte;
	}
}
