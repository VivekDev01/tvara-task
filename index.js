import express from 'express';
import axios from 'axios';
import dotenv from 'dotenv';
import { GoogleGenAI } from "@google/genai";

dotenv.config();

const app = express();
app.use(express.json());

const ai = new GoogleGenAI({});

async function main(prompt) {
  try {
    const response = await ai.models.generateContent({
    model: "gemini-2.5-flash",
    // contents: "Explain how AI works in a few words",
    contents: prompt,
  });
  console.log(response.text);
  return response;
  } catch (error) {
    console.log(error)
  }
}

app.post('/ask-gemini', async(req, res)=>{
    try {
        // console.log(req.body);
        const prompt = req.body.prompt;
        let response = await main(prompt);
        let text = response.text;
        res.status(200).json({text});
    } catch (error) {
        console.log(error)
    }
})

// main()

app.listen(3000, ()=>{
    console.log('app is running');
})