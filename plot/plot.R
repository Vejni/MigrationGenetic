library(readr)
library(dplyr)
library(scales)
library(ggplot2)
library(ggrepel)

actual <- c(14177, 13031, 9762, 11271, 8688, 7571, 6983, 4778, 2067, 1586, 793, 0)

weighted_pred <- c(14553.969743, 12777.868609, 11205.866652, 9814.397688, 8582.459494, 7490.668744, 6696.809693, 4644.070252, 3312.737830, 2170.538354, 1190.712693, 0.000000)
maxnorm_pred <- c(13617.193993, 12395.004501, 11150.308408, 9882.691591, 8591.732230, 7277.000687, 5938.059376, 4574.462626, 3185.756539, 1771.478843, 331.158739, 0.000000)

# Predicted vs actual
df = data.frame(
  Year = c(2006:2017),
  Observations = actual,
  Predicted = weighted_pred
)
df$Residuals = df$Observations - df$Predicted

ggplot(data = df) + 
  geom_line(aes(x = Year, y = Predicted, group = 1, color = "Predicted")) +
  geom_line(aes(x = Year, y = Observations, group = 1, color = "Actual")) +
  geom_point(aes(x = Year, y = Predicted, group = 1, color = "Predicted")) + 
  geom_point(aes(x = Year, y = Observations, group = 1, color = "Actual")) + 
  geom_label_repel(aes(x = Year, y = Predicted, label = Predicted), 
                   size = 3,
                   box.padding   = 1.5,
                   point.padding = 0.5,
                   force         = 75,
                   segment.size  = 0.2,
                   segment.color = "grey50",
                   direction     = "x") +
  xlab('Year') +
  ylab('Population') + 
  scale_x_continuous(breaks = Year) +
  theme_gray() + 
  labs(colour = "") +
  ggtitle("Fitted Model Predictions with Weighted Norm")

ggplot(data = df) +
  geom_point(aes(x = Year, y = Residuals, group = 1), color = "blue") +
  geom_hline(aes(yintercept = 0)) +
  ggtitle("Fitted Model Predictions with Weighted Norm")

